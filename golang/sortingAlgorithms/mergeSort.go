package main

import (
	"fmt"
)

func merge(array []int, left int, mid int, right int) {
	var n1 = mid - left + 1
	var n2 = right - mid

	leftArray := make([]int, n1)
	rightArray := make([]int, n2)

	for i := 0; i < n1; i++ {
		leftArray[i] = array[left+i]
	}

	for j := 0; j < n2; j++ {
		rightArray[j] = array[mid+1+j]
	}

	// Initial indexes of first and second subarrays
	i, j := 0, 0

	// Initial index of merged subarray array
	k := left

	for i < n1 && j < n2 {
		if leftArray[i] <= rightArray[j] {
			array[k] = leftArray[i]
			i++
		} else {
			array[k] = rightArray[j]
			j++
		}

		k++
	}

	/* Copy remaining elements of L[] if any */
	for i < n1 {
		array[k] = leftArray[i]
		i++
		k++
	}

	for j < n2 {
		array[k] = rightArray[j]
		j++
		k++
	}
}

func MergeSort(array []int, left int, right int) {
	if left < right {
		// pi is partioıning index
		mid := left + (right-left)/2

		MergeSort(array, left, mid)
		MergeSort(array, mid+1, right)

		merge(array, left, mid, right)
	}
}

func main() {
	array := []int{23, 16, 68, 75, 12, 26, 47, 51}

	n := len(array)

	MergeSort(array, 0, n-1)

	fmt.Println(array)
}
