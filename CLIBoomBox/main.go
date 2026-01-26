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
var isFast bool = false
var isBack bool = false
var ver float32 = 0.1

// TUI Stuff from Bubble tea
// Set what is items will be displayed
type model struct {
	playerOptions []string
	cursor        int
	playerCtrld   *beep.Ctrl
	playerSpeedd  *beep.Resampler
	streamerd     beep.StreamSeekCloser
}

// Sets what the options for the items are
func initialmodel(pc *beep.Ctrl, ps *beep.Resampler, st beep.StreamSeekCloser) model {
	return model{
		//Player options
		playerOptions: []string{"Play/Pause", "Restart", "Fastfoward", "Rewind", "Quit"},
		playerCtrld:   pc,
		playerSpeedd:  ps,
		streamerd:     st,
	}
}

func (m model) Init() tea.Cmd {
	return nil
}

// Control what happens during the tea loop
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
					m.playerCtrld.Paused = true
					isPause = false
				} else if !isPause {
					m.playerCtrld.Paused = false
					isPause = true
				}

			} else if m.cursor == 1 {
				//Restart
				m.streamerd.Seek(0)

			} else if m.cursor == 2 {
				//fastfoward
				if isFast {
					m.playerSpeedd.SetRatio(m.playerSpeedd.Ratio() - 6)
					isFast = false
				} else if !isFast {
					m.playerSpeedd.SetRatio(m.playerSpeedd.Ratio() + 6)
					isFast = true
				}

			} else if m.cursor == 3 {
				//Rewind
			} else if m.cursor == 4 {
				//Quit
				return m, tea.Quit
			}

		}
	}

	// Returns the updated model
	return m, nil
}

// Draws what you see on the screen
func (m model) View() string {
	s := "==============================\n"
	s += fmt.Sprintf("  CLI Boombox ver. %.1f \n", ver)
	s += "==============================\n\n"
	s += " Controls:\n\n"

	//Draw the player options
	for i, showOption := range m.playerOptions {
		// What is the cursor on
		cursorL := " "
		cursorR := " "
		if m.cursor == i {
			cursorL = ">"
			cursorR = "<"
		}

		// Draws the row
		// Render the row
		s += fmt.Sprintf("%s %s %s \n", cursorL, showOption, cursorR)
	}
	s += "\n==============================\n\n"
	return s
}

func main() {
	var userInput string
	var filePath string

	//TODO Check if the file exists and if it does
	filePath = os.Args[1]
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
	playerSpeed := beep.ResampleRatio(4, 1, playerCtrl)

	speaker.Play(playerSpeed)

	//Show TUI
	tuiP := tea.NewProgram(initialmodel(playerCtrl, playerSpeed, streamer))
	if _, err := tuiP.Run(); err != nil {
		fmt.Print("Error loading TUI")
		os.Exit(1)
	}

	speaker.Close()

}
