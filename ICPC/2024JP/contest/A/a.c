#include <stdio.h>

int main(void){
    
    while(1){
        int n;
        int late = 300;
        int a;
        
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            if (late - a >= 0){
                late -= a;
            }
        }
        printf("%d\n", 300-late);
    }

    return 0;
}