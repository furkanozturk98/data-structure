package main

import (
	"fmt"
)

func swap(array []int, i int, j int) {
	array[i], array[j] = array[j], array[i]
}

func partition(array []int, low int, high int) int {
	pivot := array[high]
	i := low - 1

	for j := low; j <= high-1; j++ {
		if array[j] < pivot {
			i++
			swap(array, i, j)
			fmt.Println(array)
		}
	}

	swap(array, i+1, high)

	return i + 1
}

func QuickSort(array []int, low int, high int) {
	if low < high {
		// pi is partioıning index
		pi := partition(array, low, high)

		QuickSort(array, low, pi-1)
		QuickSort(array, pi+1, high)
	}
}

func main() {
	array := []int{23, 16, 68, 75, 12, 26, 47, 51}

	n := len(array)

	QuickSort(array, 0, n-1)

	fmt.Println(array)
}
