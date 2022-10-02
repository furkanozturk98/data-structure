package main

import (
	"fmt"
)

func InsertionSort(array []int) []int {
	n := len(array)

	for i := 1; i < n; i++ {
		key := array[i]

		j := i - 1

		for j >= 0 && array[j] > key {
			array[j+1] = array[j]
			j = j - 1
		}

		array[j+1] = key
	}

	return array
}

func main() {
	array := []int{23, 16, 68, 75, 12, 26, 51}
	fmt.Println(InsertionSort(array))
}
