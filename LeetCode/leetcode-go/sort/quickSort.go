package main

import "fmt"

func QuickSort(nums []int) []int {
    quickSort(nums, 0, len(nums) - 1)
    return nums
}

func quickSort(nums []int, start, end int) {
    if start < end {
        p := partition(nums, start, end)
        quickSort(nums, start, p - 1)
        quickSort(nums, p + 1, end)
    }
}

func partition(nums []int, start, end int) int {
    i := start
    tmp := nums[end]

    for j := start; j < end; j ++ {
        if nums[j] < tmp {
            swap(nums, i, j)
            i ++
        }
    }
    swap(nums, i, end)
    return i
}

func swap(nums []int, i, j int) {
    tmp := nums[i]
    nums[i] = nums[j]
    nums[j] = tmp
}

func main() {
    nums := []int{4,1,2,7,6,4,9,3,0,8}
    fmt.Println(QuickSort(nums))
}
