// 2024/11/26 13:21:12
// 2024/11/26 13:34:52 TLE
// 2024/11/26 13:47:19 TLE
// 2024/11/26 13:58:34 TLE
package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)

	// // 間に合わない？？
	// A := make([]int, N)
	// B := make([]int, N)
	// for i := 0; i < N; i++ {
	// 	fmt.Scanf("%d", &A[i])
	// }
	// for i := 0; i < N; i++ {
	// 	fmt.Scanf("%d", &B[i])
	// }

	var A []int
	var B []int
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scanf("%d", &tmp)
		A = append(A, tmp)
	}
	for i := 0; i < N; i++ {
		var tmp int
		fmt.Scanf("%d", &tmp)
		B = append(B, tmp)
	}

	// // 間に合わない？？？
	// sort.Sort(sort.IntSlice(A))
	// sort.Sort(sort.IntSlice(B))
	// fmt.Println(A[len(A)-1] + B[len(B)-1])

	max_A := A[0] // MinIntとか無いんかね
	max_B := B[0]
	for _, a := range A {
		if max_A < a {
			max_A = a
		}
	}
	for _, b := range B {
		if max_B < b {
			max_B = b
		}
	}
	fmt.Println(max_A + max_B)
}

/*
fmt駄目なのかよ・・・
> 【競プロ】Goの標準入力でTLEを防ぐコツ
> https://zenn.dev/pikarich/articles/426f8f11cd6bc3
*/
