// 2024/03/30 22:16:28
// 2024/03/30 22:37:18 29WA overflow
// 2024/03/30 22:52:34 1WA
// 2024/03/30 23:15:03 3WA
// 2024/03/30 23:26:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a, b;
    long long C;
    cin >> a >> b >> C;

    int num1 = 0; // Cの1の数
    long long c = C;    
    while (c) {
        // cout << c % 2 << ' '; // debug
        num1 += c % 2;
        c /= 2;
    }
    // cout << endl; // debug
    int num0 = a + b - num1; // Cの0の数。XとYで等しく分配する必要あり。(x,y)=(1,1)による0
    if (a + b < num1 || num0 % 2 || a < num0 / 2 || b < num0 / 2) {
        cout << -1 << endl;
        return 0;
    }
    num0 /= 2;

    long long X = 0, Y = 0;
    int a_for1 = a - num0; // aの、Cを1にするために使える1の数 (x,y)=(1,0)による1
    int i = 0;
    c = C;
    while (c || num0) {
        if (61 == i) {
            break;
        }
        if (c % 2) {
            if (a_for1) {
                X += (long long)1 << i;
                a_for1--;
            } else {
                Y += (long long)1 << i;
            }
        } else {
            if (num0) {
                X += (long long)1 << i;
                Y += (long long)1 << i;
                num0--;
            }
        }
        c /= 2;
        i++;
    }
    long long MAX_LIM = (long long)1 << 60;
    if (MAX_LIM < X || MAX_LIM < Y) {
        cout << -1 << endl;
        return 0;
    }
    cout << X << ' ' << Y << endl;

    // /* debug */
    // i = 0;
    // while (X) {
    //     cout << X % 2 << ' ';
    //     X /= 2;
    //     i++;
    // }
    // cout << endl;
    // i = 0;
    // while (Y) {
    //     cout << Y % 2 << ' ';
    //     Y /= 2;
    //     i++;
    // }
    return 0;
}
/*
Cを2進数表記して、
a個の1とb個の1をうまい感じに分配する問題ね。(2024/03/30 22:18:07)


3 4 7
7 = 00111
    11001
    11110
あー動的計画法使いそうなきもしなくもなくもなくなく(2024/03/30 22:21:34)
0になるということは、いや、
1になる部分はX側とY側の合計が常に1だ。
そこから決めていけば良くない？(2024/03/30 22:22:23)

あー分かった。1が余るパターンが有るのか。
XやYの上限2^60を超えてしまう。
*/
