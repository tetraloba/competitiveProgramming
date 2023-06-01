#include <stdio.h>
int main(void){
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", a[a[a[0]]]);
    return 0;
}