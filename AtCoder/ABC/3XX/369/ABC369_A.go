// 2024/11/24 13:31:00
// 2024/11/24 14:16:42 AC
package main

import (
	"fmt"
	"os"
	"sort"
)

func isAriPro(p int, q int, r int) bool {
	s := []int{p, q, r}
	sort.Slice(s, func(i int, j int) bool { return s[i] < s[j] })
	fmt.Fprintf(os.Stderr, "%d %d %d -> %v\n", p, q, r, s)
	return s[2]-s[1] == s[1]-s[0]
}

func main() {
	var (
		A int
		B int
	)
	fmt.Scan(&A, &B)
	// 無難に全探索書いてみるか。 (2024/11/24 13:35:58)
	ans := 0
	for x := -98; x <= 199; x++ {
		if isAriPro(A, B, x) {
			ans++
		}
	}
	fmt.Println(ans)
}
