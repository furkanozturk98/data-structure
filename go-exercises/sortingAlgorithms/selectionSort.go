package main

import (
	"fmt"
)

func SelectionSort(array []int) []int {
	n := len(array)

	for i := 0; i < n-1; i++ {
		minIndex := i

		for j := i + 1; j < n; j++ {
			if array[j] < array[minIndex] {
				minIndex = j
			}
		}

		array[minIndex], array[i] = array[i], array[minIndex]
	}

	return array
}

func main() {
	array := []int{23, 16, 68, 75, 12, 26, 51}
	fmt.Println(SelectionSort(array))
}
