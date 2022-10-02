package main

import (
	"fmt"
)

func BubbleSort(array []int) []int {
	n := len(array)

	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {

			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j]
			}

		}
	}
	return array
}

func main() {
	array := []int{23, 16, 68, 75, 12, 26, 51}
	fmt.Println(BubbleSort(array))
}
