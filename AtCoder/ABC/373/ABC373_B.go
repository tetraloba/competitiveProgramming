// 2024/11/26 13:11:00
// 2024/11/26 13:19:23 AC.
package main

import "fmt"

func diff(a int, b int) int {
	if a < b {
		return b - a
	} else {
		return a - b
	}
}

func main() {
	var S string
	fmt.Scanf("%s", &S)
	var arr [26]int
	for i, c := range S {
		arr[int(c-'A')] = i
	}
	var ans int
	for i := 0; i < 26-1; i++ {
		ans += diff(arr[i], arr[i+1])
	}
	fmt.Println(ans)
}
