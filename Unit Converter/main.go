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

// Distance
func mi2km(f float64) {
	fmt.Println(f * 1.609344)
}

func km2mi(f float64) {
	fmt.Println(f * 0.6214)
}

func ft2m(f float64) {
	fmt.Println(f * 0.3048)
}

func m2ft(f float64) {
	fmt.Println(f * 3.28084)
}

func in2cm(f float64) {
	fmt.Println(f * 2.54)
}

func cm2in(f float64) {
	fmt.Println(f * 0.3937008)
}

func in2mm(f float64) {
	fmt.Println(f * 25.4)
}

func mm2in(f float64) {
	fmt.Println(f * 0.03937008)
}

// Temp
func f2c(f float64) {
	fmt.Println((f - 32) * 5 / 9)
}

func c2f(f float64) {
	fmt.Println((f * 1.8) + 32)
}

func main() {
	var helpText string = `Valid Converts:
	lb2kg	kg2lb
	oz2g	g2oz
	mi2km	km2mi
	ft2m	m2ft
	in2cm	cm2in
	in2mm	mm2in
	f2c	c2f`

	var conType string
	if len(os.Args) > 1 {
		conType = os.Args[1]
	}
	var conNum string //Number is string beacuse inputs are strings, needs to be converted to float
	if len(os.Args) > 2 {
		conNum = os.Args[2]
	} else {
		conNum = "1"
	}

	conNumf, _ := strconv.ParseFloat(conNum, 64)

	//Converters
	if strings.Compare(conType, "lb2kg") == 0 {
		lb2kg(conNumf)
	} else if strings.Compare(conType, "kg2lb") == 0 {
		kg2lb(conNumf)
	} else if strings.Compare(conType, "oz2g") == 0 {
		oz2g(conNumf)
	} else if strings.Compare(conType, "g2oz") == 0 {
		g2oz(conNumf)
	} else if strings.Compare(conType, "mi2km") == 0 {
		mi2km(conNumf)
	} else if strings.Compare(conType, "km2mi") == 0 {
		km2mi(conNumf)
	} else if strings.Compare(conType, "ft2m") == 0 {
		ft2m(conNumf)
	} else if strings.Compare(conType, "m2ft") == 0 {
		m2ft(conNumf)
	} else if strings.Compare(conType, "in2cm") == 0 {
		in2cm(conNumf)
	} else if strings.Compare(conType, "cm2in") == 0 {
		cm2in(conNumf)
	} else if strings.Compare(conType, "in2mm") == 0 {
		ft2m(conNumf)
	} else if strings.Compare(conType, "mm2in") == 0 {
		mm2in(conNumf)
	} else if strings.Compare(conType, "f2c") == 0 {
		f2c(conNumf)
	} else if strings.Compare(conType, "c2f") == 0 {
		c2f(conNumf)
	} else if strings.Compare(conType, "help") == 0 {
		fmt.Println(helpText)
		fmt.Println("Follow this by the number you want to convert")
	} else {
		fmt.Println("Invalid Convert. Type unicon help to see all valid converts")
	}

}
