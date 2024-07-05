#include<stdio.h>
#include<stdlib.h>

typedef struct _Pos
{
    int x;
    int y;
} Pos;


int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int ans = 0;
        Pos cur;
        cur.x = 0;
        cur.y = 0;

        Pos dest;
        scanf("%d %d", &dest.x, &dest.y);
        if(dest.x < 0 && dest.y > 0){
            // 第2象限
            while(1){
                if(dest.x == cur.x || dest.y == cur.y){
                    break;
                }
                cur.x -= 1;
                cur.y += 1;
                ans++;
            }
            ans += abs(dest.x-cur.x)+abs(dest.y-cur.y);
        }
        else if(dest.x > 0 && dest.y < 0){
            // 第4象限
            while(1){
                if(dest.x == cur.x || dest.y == cur.y){
                    break;
                }
                cur.x += 1;
                cur.y -= 1;
                ans++;
            }
            ans += abs(dest.x-cur.x)+abs(dest.y-cur.y);
        }else{
            // 第1,3象限と境界線上
            ans = abs(dest.x)+abs(dest.y);
        }
        printf("%d\n", ans);
    }
    return 0;
}