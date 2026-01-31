package main

import (
	"fmt"
	"time"
)

func main() {
	var currentTime time.Time
	var currentHour int
	var currentMinute int

	for true {
		currentTime = time.Now()
		currentHour = currentTime.Hour()
		currentMinute = currentTime.Minute()
		fmt.Print("\r", currentHour, ":", currentMinute)
		time.Sleep(10 * time.Second)

	}

}
