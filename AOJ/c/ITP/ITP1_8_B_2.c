#include <stdio.h>
int main(void){
    int ch, sum;
    while (1) {
        sum = 0;
        while ((ch = getchar()) != '\n') {
            sum += ch - '0';
        }
        if (sum == 0) {
            break;
        }
        printf("%d\n", sum);
    }
    return 0;
}