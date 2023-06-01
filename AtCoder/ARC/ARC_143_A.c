//2022/07/16 20:53 AC. テキトウに書いたけど通って草
#include <stdio.h>
int main(void){
    long long int A, B, C;
    scanf("%lld %lld %lld", &A, &B, &C);
    long long int tmp;
    if (B < A) {
        tmp = A;
        A = B;
        B = tmp;
    }
    if (C < B) {
        tmp = B;
        B = C;
        C = tmp;
        if (B < A) {
            tmp = A;
            A = B;
            B = tmp;
        }
    }
    // tmp = A;
    tmp = 0;
    if ((A + B + C) % 2) {
        A--;
        B--;
        C--;
        tmp++;
    }
    if (A >= C - B) {
        tmp += (C - B) + (C - A); //2つから引く操作
        tmp += A - (C - B); //3つから引く操作
    } else {
        tmp = -1;
    }
    printf("%lld\n", tmp);
    return 0;
}
// A %= 2;
// B -= A / 2;
// C -= A / 2;
// while (A <= tmp) {
//     if (A > C - B) {

//     }
// }
    // 1 1 2
    // 6 6 8 LLCC
    // 6 5 7 CR
    // 6 4 6 CR
    // 5 4 5 LR
    // 4 4 4 LR
    // 1 1 3
    // 0 0 2
    // -1 0 1
    // -2 0 0
    // -2 -1 -1
    // -2 -2 -2
    // 6 8 10 (6)
    // 6 7 9
    // 6 6 8 min > max - mid ?