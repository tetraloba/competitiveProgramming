//2022/07/18 00:43:48
//2022/07/18 00:53:19 AC. なにこれ・・・
#include <stdio.h>
int main(void){
    int N, num[2001] = {0};
    scanf("%d", &N);
    for (int i = 0; i < 2 * N + 1; i++) {
        for (int j = 0; j < 2 * N + 1; j++) {
            if (!num[j]) {
                num[j] = 1;
                printf("%d\n", j + 1);
                fflush(stdout);
                break;
            }
        }
        int tmp;
        scanf("%d", &tmp);
        if (!tmp) {
            break;
        }
        num[tmp - 1] = 1;
    }
    return 0;
}