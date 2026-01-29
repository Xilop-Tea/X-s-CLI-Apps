package main

import (
	"fmt"
	"os"
	"time"

	tea "github.com/charmbracelet/bubbletea"
)

type model struct {
	clockFunc   []string
	cursor      int
	currentTime time.Time
}

func clockModel() model {
	return model{
		clockFunc:   []string{"Clock", "Alarm", "Stopwath"},
		currentTime: time.Now(),
	}
}

func (m model) Init() tea.Cmd {
	return nil
}

func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyMsg:
		//Controlls for the clock
		switch msg.String() {
		//Exit
		case "ctrl+c", "q":
			return m, tea.Quit

		//Move Cursor
		case "left":
			if m.cursor > 0 {
				m.cursor--
			}

		case "right":
			if m.cursor < len(m.clockFunc)-1 {
				m.cursor++
			}
		}
	}

	//clock
	m.currentTime = time.Now()
	return m, nil
}

func (m model) View() string {
	s := "Tik Tok Clicking Clock"

	for i, clockFunc := range m.clockFunc {
		s += fmt.Sprintf("Time: %d:%d\n\n", m.currentTime.Hour(), m.currentTime.Minute())

		cursor := " "
		if m.cursor == i {
			cursor = "^"
		}
		s += fmt.Sprintf("%s  ", clockFunc)
		s += fmt.Sprintf("%s", cursor)
	}

	return s
}

func main() {
	clock := tea.NewProgram(clockModel())
	if _, err := clock.Run(); err != nil {
		fmt.Print("Oopsy Doopsy, I did a woopsy")
		os.Exit(1)
	}

}
