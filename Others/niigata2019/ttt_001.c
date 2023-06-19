#include <stdio.h>
#include <stdlib.h>
int max = 1111;
// 考えられる最小値は1111
// よって最大値の初期値を1111とする
// maxより大きい値が登場すれば、
// そのたびに値を更新する

// f2, f3, f4 は
// 4つの数を全てのパターンの並べ替えを行う関数
// f1 は
// その時の並びの数値を組み合わせて一つの数にする関数
// f1にてmaxより大きな値が完成すれば、maxを更新する
void f1(int a, int b, int c, int d)
{
    char as[16];
    char bs[16];
    char cs[16];
    char ds[16];
    char str[64];
    snprintf(as, 16, "%d", a);
    snprintf(bs, 16, "%d", b);
    snprintf(cs, 16, "%d", c);
    snprintf(ds, 16, "%d", d);
    sprintf(str, "%s%s%s%s", as, bs, cs, ds);
    int now = atoi(str);
    if(now > max)
    {
        max = now;
    }
}

void f2(int a, int b, int c, int d)
{
    f1(a, b, c, d);
    f1(a, b, d, c);
}

void f3(int a, int b, int c, int d)
{
    f2(a, b, c, d);
    f2(a, c, b, d);
    f2(a, d, b, c);
}

void f4(int a, int b, int c, int d)
{
    f3(a, b, c, d);
    f3(b, a, c, d);
    f3(c, a, b, d);
    f3(d, a, b, c);
}

int main(void)
{
    int n[4], i;
    // 配列nに値を代入する

    for(i = 0; i < 4; i++)
    {
        // printf("%dつ目の整数 : ", i+1);
        scanf("%d", &n[i]);

        // 1~99以外ならもう一度値を入力させる
        if(n[i] < 1 || 99 < n[i])
        {
            puts("1~99の整数を入力");
            i--;
        }
    }

    f4(n[0], n[1], n[2], n[3]);
    // 最終的なmaxを表示する
    // printf("max : %d\n", max);
    printf("%d\n", max);
    return 0;
}