//2022-07-23 20:23:29
//2022-07-23 20:25:43 AC
#include <stdio.h>
int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    if (b - a == 1 || b - a == 9) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}