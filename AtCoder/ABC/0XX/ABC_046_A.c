//2022/05/29 22:28
//2022/05/29 22:42 AC デバッグ用の出力を残したまま提出するというミスort
#include <stdio.h>
#define NUM 3
int main(void){
    int arr[NUM], count = NUM;
    for (int i = 0; i < NUM; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < NUM; i++) {
        for (int j = i + 1; j < NUM; j++) {
            if (arr[i] == arr[j]) {
                //printf("%d(%d) = %d(%d)\n", arr[i], i, arr[j], j);
                count--;
                break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}