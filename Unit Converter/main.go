package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Weight
func lb2kg(f float64) {
	fmt.Println(f * 0.45359237)
}

func kg2lb(f float64) {
	fmt.Println(f * 2.20462)
}

func oz2g(f float64) {
	fmt.Println(f * 28.34952)
}

func g2oz(f float64) {
	fmt.Println(f * 0.03527396195)
}

func main() {
	conType := os.Args[1]
	conNum := os.Args[2]
	conNumf, _ := strconv.ParseFloat(conNum, 64)
	validType := false

	fmt.Print("\n")
	//Converters
	if strings.Compare(conType, "lb2kg") == 0 {
		lb2kg(conNumf)
		validType = true
	}

	if strings.Compare(conType, "kg2lb") == 0 {
		kg2lb(conNumf)
		validType = true
	}

	if strings.Compare(conType, "oz2g") == 0 {
		oz2g(conNumf)
		validType = true
	}

	if strings.Compare(conType, "g2oz") == 0 {
		g2oz(conNumf)
		validType = true
	}
	if !validType {
		fmt.Println("Invalid")
	}

	fmt.Print("\n")

}
