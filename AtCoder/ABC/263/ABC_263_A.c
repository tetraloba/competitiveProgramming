//2022/08/06 21:01:15
//2022/08/06 21:07:06
#include <stdio.h>
int main(void){
    int A, tmp1, tmp2, cnt1 = 0, cnt2 = 0;
    scanf("%d", &tmp1);
    cnt1++;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A);
        if (A == tmp1) {
            cnt1++;
        } else if (!cnt2 || tmp2 == A) {
            tmp2 = A;
            cnt2++;
        } else {
            puts("No");
            return 0;
        }
    }
    if ((cnt1 == 2 || cnt2 == 2) && (cnt1 == 3 || cnt2 == 3)) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}