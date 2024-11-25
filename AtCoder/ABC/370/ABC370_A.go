// 2024/11/25 09:22:05
// 2024/11/25 09:26:39 AC.
package main

import "fmt"

func main() {
	var L, R int
	fmt.Scanf("%d %d", &L, &R)
	if (L+R)%2 == 1 {
		if L == 1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	} else {
		fmt.Println("Invalid")
	}
}
