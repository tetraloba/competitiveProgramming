#include<stdio.h>

typedef struct _hoge
{
    int index_r;
    int index_f;
    int r;
} hoge;


void print_nxn(int arr[], int n, hoge fuga);
hoge judge_y_n(int arr[], int n);


int main(void){
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0){
            break;
        }

        int arr[50] = {-1};
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        hoge r = judge_y_n(arr, n);
        if(hoge.r == 1){
            print_nxn(arr, n, r);

        }else{
            printf("No\n");
        }
    }
    return 0;
}

void print_nxn(int arr[], int n, hoge fuga){
    printf("Yes\n");
    if(fuga.index_r == -1 && fuga.index_f == -1){
        for(int i = 0; i < n; i++){
            printf("%d ", arr[n-i-1]);
        }
        printf("\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[n-i-1]);
                    }
                    printf("\n");
                }else if(i == n-1){
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }

            }
        }

    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ;
            ;
        }
        printf("\n");
    }
}

hoge judge_y_n(int arr[], int n){
    hoge piyo;

    if(arr[0] == arr[n-1]){
        piyo.r = 1;
        piyo.index_r = -1;
        piyo.index_f = -1;
    }else{
        for(int i = (n-1)/2; i < n; i++){
            if(arr[0] == arr[i]){
                for(int j = n/2; j > -1; j--){
                    if(arr[n-1] == arr[j]){
                        piyo.r = 1;
                        piyo.index_f = i;
                        piyo.index_r = j;
                        return piyo;
                    }
                }
            }
        }
    }
    piyo.r = 0;
    return piyo;
    
}