#include <stdio.h>
double max = 1111;
// 考えられる最小値を最大値の初期値とする。
// maxより大きい値が登場すれば、
// そのたびに値を更新する

double n[4];
// 値を格納し、管理する配列

// f2, f3, f4 は
// 4つの数の全パターンの並べ替えを行う関数
// f1 は
// 4つの数字を合わせて一つの数値にし、
// maxより大きな値になれば、maxを更新する関数
void f1(double a, double b, double c, double d)
{
    double now = 0;
    now += a * 10 * 10 * 10;
    now += b * 10 * 10;
    now += c * 10;
    now += d;
    if(now > max)
    {
        max = now;
        n[0] = a;
        n[1] = b;
        n[2] = c;
        n[3] = d;
    }
}

void f2(double a, double b, double c, double d)
{
    f1(a, b, c, d);
    f1(a, b, d, c);
}

void f3(double a, double b, double c, double d)
{
    f2(a, b, c, d);
    f2(a, c, b, d);
    f2(a, d, b, c);
}

void f4(double a, double b, double c, double d)
{
    f3(a, b, c, d);
    f3(b, a, c, d);
    f3(c, a, b, d);
    f3(d, a, b, c);
}

int main(void)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        // printf("%dつ目の整数 : ", i+1);
        scanf("%lf", &n[i]);

        // 1~99以外ならもう一度値を入力させる
        if(n[i] < 1 || 99 < n[i])
        {
            puts("1~99の整数を入力");
            i--;
        }
    }

    for(i = 0; i < 4; i++)
    {
        // 全ての値を1以上10未満の値にする
        if(n[i] > 10)
        {
            n[i] /= 10.0;
        }
    }

    // 探索開始
    f4(n[0], n[1], n[2], n[3]);

    // 最終的なmaxを作った数字の並びを表示する
    // printf("max : ");
    for(i = 0; i < 4; i++)
    {
        // 小数点以下の値がある場合は
        // 10倍して整数に直す
        if(n[i] - (int)n[i] != 0)
        {
            n[i] *= 10;
        }
        printf("%d", (int)n[i]);
    }
    putchar('\n');
    return 0;
}