// 2024/11/26 13:59:48
// 2024/11/26 14:03:26 AC.
#include <stdio.h>
int main(void) {
	int N;
    scanf("%d", &N);

	int A[N];
	int B[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &B[i]);
	}

	int max_A = A[0];
	int max_B = B[0];
	for (int i = 0; i < N; i++) {
		if (max_A < A[i]) {
			max_A = A[i];
		}
	}
	for (int i = 0; i < N; i++) {
		if (max_B < B[i]) {
			max_B = B[i];
		}
	}
	printf("%d", max_A + max_B);
}
/*
まあ行けるよな…？
なんでほぼ同じこと書いてあるのにGoだと駄目なんだ…？
*/
