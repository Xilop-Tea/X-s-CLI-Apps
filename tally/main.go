package main

import (
	"fmt"
	"os"

	tea "github.com/charmbracelet/bubbletea"
)

type model struct {
	tallys       []string
	tallysNumber []int
	cursor       int
}

func initialmodel(s1 string, s2 string) model {
	return model{
		tallys:       []string{s1, s2},
		tallysNumber: []int{0, 0},
	}
}

func (m model) Init() tea.Cmd {
	return nil
}

func (m model) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyMsg:
		switch msg.String() {
		case "up":
			if m.cursor > 0 {
				m.cursor--
			}
		case "down":
			if m.cursor < len(m.tallys)-1 {
				m.cursor++
			}
		case "ctrl+c":
			return m, tea.Quit

		case " ", "enter":
			m.tallysNumber[m.cursor]++

		}
	}
	return m, nil
}

func (m model) View() string {
	s := "Tally\n"

	for i, tally := range m.tallys {
		cursor := " "
		if m.cursor == i {
			cursor = ">"
		}

		tallyNum := m.tallysNumber[i]
		s += fmt.Sprintf("%s %s: %d \n", cursor, tally, tallyNum)
	}
	return s
}

func main() {
	var tally1 string
	var tally2 string

	fmt.Print("What is Tally 1 --> ")
	fmt.Scanln(&tally1)
	fmt.Print("What is Tally 2 --> ")
	fmt.Scanln(&tally2)

	draw := tea.NewProgram(initialmodel(tally1, tally2))
	if _, err := draw.Run(); err != nil {
		os.Exit(1)
	}
}
