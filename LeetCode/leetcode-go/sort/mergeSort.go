package main

import "fmt"

func mergeSort(nums []int) []int {
    if len(nums) <= 1 {
        return nums
    }
    mid := len(nums) - 1
    left := mergeSort(nums[:mid])
    right := mergeSort(nums[mid:])
    result := merge(left, right)
    return result
}

func merge(left, right []int) (result []int) {
    l := 0
    r := 0

    for l < len(left) && r < len(right) {
        if left[l] < right[r] {
            result = append(result, left[l])
            l ++
        } else {
            result = append(result, right[r])
            r ++
        }
    }
    result = append(result, left[l:]...)
    result = append(result, right[r:]...)
    return result
}

func main() {
    nums := []int{4,2,8,5,2,6,0,7}
    fmt.Println(mergeSort(nums))
}
