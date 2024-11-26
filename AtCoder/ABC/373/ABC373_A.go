// 2024/11/26 12:49:02
// 2024/11/26 13:09:59 AC.
package main

import "fmt"

func main() {
	var S [12]string
	for i := 0; i < 12; i++ {
		fmt.Scanf("%s", &S[i])
	}
	var ans int
	for i, s := range S {
		if len(s) == i+1 {
			ans++
		}
	}
	fmt.Println(ans)
}
