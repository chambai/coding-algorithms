package main

import "fmt"

func MaxHeapify(arr []int, size int, index int) {
	if index < 0 || index >= size {
		return
	}

	flag := true

	for flag && index < size {
		left := 2 * index + 1 // start from zero
		right := 2 * index + 2
		var largest int

		if left < size && arr[left] > arr[index] {
			largest = left
		} else {
			largest = index
		}
		if right < size && arr[right] > arr[index] {
			largest = right
		}
		if largest != index {
			Swap(arr, largest, index)
			index = largest
		} else {
			flag = false
		}
	}
}

func BuildMaxHeap(arr []int, size int) {
	for i := (size - 1) / 2; i >= 0; i -- {
		MaxHeapify(arr, size, i)
	}
}

func HeapSort(arr []int, size int) {
	if size == 0 {
		return
	}
	len := size
	BuildMaxHeap(arr, len)
	for i := size - 1; i >= 1; i -- {
		Swap(arr, 0, i)
		len --
		MaxHeapify(arr, len, 0)
	}
}

func Swap(arr []int, a, b int) {
	arr[a], arr[b] = arr[b], arr[a]
}

func main() {
	arr := []int{4,6,5,2}
	HeapSort(arr, len(arr))
	fmt.Println(arr)
}