package main

import (
	"fmt"
	"log"
	"os"
	"time"

	tea "github.com/charmbracelet/bubbletea"
	"github.com/gopxl/beep"
	"github.com/gopxl/beep/mp3"
	"github.com/gopxl/beep/speaker"
)

var isPause bool = false

// TUI Stuff from Bubble tea
// Set what is items will be displayed
type model struct {
	playerOptions []string
	cursor        int
	playerCtrld   *beep.Ctrl
}

// Sets what the options for the items are
func initialmodel(pc *beep.Ctrl) model {
	return model{
		//Player options
		playerOptions: []string{"Play/Pause", "Restart", "Fastfoward", "Quit"},
		playerCtrld:   pc,
	}
}

func (m model) Init() tea.Cmd {
	return nil
}

// Control where the cursor is
func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	//Set the controls up

	//Check if any key has been pressed
	switch msg := msg.(type) {
	case tea.KeyMsg:
		//Check for what is being pressed
		switch msg.String() {
		case "up":
			if m.cursor > 0 {
				m.cursor--
			}
		case "down":
			if m.cursor < len(m.playerOptions)-1 {
				m.cursor++
			}
		case "ctrl+c":
			return m, tea.Quit

		//Make controlls usable
		case " ", "enter":
			if m.cursor == 0 {
				//pasue
				if isPause {
					isPause = false
				} else if !isPause {
					isPause = true
				}
				if isPause {
					m.playerCtrld.Paused = true
				} else if !isPause {
					m.playerCtrld.Paused = false
				}
			} else if m.cursor == 1 {
				//Restart
			} else if m.cursor == 2 {
				//fastfoward
			} else if m.cursor == 3 {
				//Quit
				//TODO add end streamer
				return m, tea.Quit

			}

		}
	}

	// Returns the updated model
	return m, nil
}

// Draws what you see on the screen
func (m model) View() string {
	s := "Controls\n\n"

	//Draw the player options
	for i, showOption := range m.playerOptions {
		// What is the cursor on
		cursor := " "
		if m.cursor == i {
			cursor = ">"
		}

		// Draws the row
		// Render the row
		s += fmt.Sprintf("%s %s\n", cursor, showOption)
	}
	return s
}

func main() {
	var userInput string
	var filePath string

	fmt.Print("Select a file to play --> ")
	fmt.Scanln(&userInput)

	//TODO Check if the file exists and if it does
	filePath = userInput
	fmt.Print(userInput)
	file, err := os.Open(filePath)
	if err != nil {
		log.Fatal(err)
	}

	//TODO add diffrent file types and set correct streamer, format based on input string
	streamer, format, err := mp3.Decode(file)
	if err != nil {
		log.Fatal(err)
	}

	speaker.Init(format.SampleRate, format.SampleRate.N(time.Second/10))
	playerCtrl := &beep.Ctrl{Streamer: beep.Loop(-1, streamer), Paused: false}
	speaker.Play(playerCtrl)

	//Show TUI
	tuiP := tea.NewProgram(initialmodel(playerCtrl))
	if _, err := tuiP.Run(); err != nil {
		fmt.Print("Error loading TUI")
		os.Exit(1)
	}

	select {}

}
