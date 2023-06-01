//2022-07-23 21:00:08
//2022-07-23 21:13:38 WA
//2022-07-23 21:17:05 AC.
#include <stdio.h>
int main(void){
    int L1, R1, L2, R2;
    scanf("%d %d %d %d", &L1, &R1, &L2, &R2);
    int ans;
    if (R1 < L2 || R2 < L1) { //L1 R1 L2 R2, L2 R2 L1 R1
        ans = 0;
    } else if (L1 < L2) {
        if (R2 < R1) { //L1 L2 R2 R1
            ans = R2 - L2;
        } else { //L1 L2 R1 R2
            ans = R1 - L2;
        }
    } else { //L2 < L1
        if (R2 < R1) { //L2 L1 R2 R1
            ans = R2 - L1;
        } else { //L2 L1 R1 R2
            ans = R1 - L1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
// L1 R1, L2 R2
//L1 R1 L2 R2 0
//L1 L2 R1 R2
//L2 L1 R1 R2
//L1 L2 R2 R1
//L2 L1 R2 R1
//L2 R2 L1 R1 0