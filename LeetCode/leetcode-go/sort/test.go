package main
import "fmt"

func main() {
    m := make(map[int]string)
    m[1] = "hello"
    fmt.Println(m)
    m1 := map[int]string{}
    m1[0]="world"
    fmt.Println(m1)
}
