//2022/08/10 07:14:03
//2022/08/10 07:20:05 AC. うーん、こうじゃないんだよなあ。。。皆の回答見てみよう。
#include <stdio.h>
long long int pow(int a, int b){
    long long int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}
int main(void){
    int n;
    scanf("%d", &n);
    if (4 < n || pow(2, n) > pow(n, 2)) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}

//これ行けるってマジ？ https://atcoder.jp/contests/abc238/submissions/33481436
//そうか、桁おばけには浮動小数点最強か。精度はこの問題では問題にならないか。
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
// int main(void){
//     double n;
//     scanf("%lf",&n);
//     if(pow(2.0,n) > n * n){
//         printf("Yes");
//     }else{
//         printf("No");
//     }
//     return 0;
// }

//これでpow使える人が居る謎。https://atcoder.jp/contests/abc238/submissions/33384647
// #include<stdio.h>
// int main()
// {
//     int n;
//     double a,b;
//     scanf("%d",&n);
//     a=pow(2,n);
//     b=pow(n,2);
//     if(a>b)
//         printf("Yes");
//     else
//         printf("No");

// }

//printfってPEにならないのか。 https://atcoder.jp/contests/abc238/submissions/33283434
// #include<stdio.h>
// #include<math.h>
// int main()
// {
//     long long int n,res1,res2;
//     scanf("%lld",&n);
//     if (n<5)
//     {
//         res1=pow(2,n);
//         res2=pow(n,2);
//         if(res1>res2)
//         {
//             printf("Yes");
//         }
//         else
//         {
//             printf("No");
//         }
//     }
//     else
//     {
//         printf("Yes");
//     }
// }

// A問題も馬鹿にできない。勉強になるなあ。