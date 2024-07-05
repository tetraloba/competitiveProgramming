#include<stdio.h>

int main(void){
    while(1){
        int n = 0, an = 0;
        int a_max = 0;
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &an);
            if(an > a_max){
                a_max = an;
            }
        }
        printf("%d\n", a_max);
    }

    return 0;
}