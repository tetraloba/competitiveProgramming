// 2023/05/14 21:46:32
// 2023/05/14 21:51:34 部分文字列か…どうするんだっけ？動的計画法？
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int cnt[10] = {0};
    int cnt_tgt = 0;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        cnt[(int)(S[i] - '0')]++;
        bool flag = true;
        for (int e : cnt) {
            if (e % 2) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cnt_tgt++;
        }
    }
    cout << cnt_tgt << endl;
    return 0;
}
// 10C2 = 10 * 9 / (2 * 1) = (1 + 9) * 9 / 2 = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9