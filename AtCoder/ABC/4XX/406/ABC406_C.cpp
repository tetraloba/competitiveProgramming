// 2025/05/23 11:33:46
// 2025/05/23 13:14:40 5WA
// 2025/05/23 13:15:53 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int &p : P) {
        cin >> p;
    }

    vector<int> outotsu(N);
    for (int i = 1; i <= N - 2; i++) {
        if (P[i - 1] > P[i] && P[i] < P[i + 1]) {
            outotsu[i] = -1;
        } else if (P[i - 1] < P[i] && P[i] > P[i + 1]) {
            outotsu[i] = 1;
        } else {
            outotsu[i] = 0;
        }
    }
    // /* debug */
    // for (int i : outotsu) {
    //     cerr << i << ' ';
    // }
    // cerr << endl;

    int l = 0;
    long long ans = 0;
    int ou = 0, totsu = 0;
    // l, r は半開区間
    for (int r = 1; r <= N; r++) {
        if (outotsu[r - 2] == -1) {
            ou++;
        } else if (outotsu[r - 2] == 1) {
            totsu++;
        }
        // cerr << '(' << l << ',' << r << ')' << ou << '-' << totsu << endl; // debug

        /* ou か totsu が2つ以上含まれる場合は1つ以下になるまでlを進める */
        while (2 <= ou || 2 <= totsu) {
            if (outotsu[l + 1] == -1) {
                ou--;
            } else if (outotsu[l + 1] == 1) {
                totsu--;
            }
            l++;
        }

        /* ou か totsu が含まれない場合は、含まれるまでrを進める */
        if (!ou || !totsu) {
            continue;
        }    

        // cerr << '(' << l << ',' << r << ')' << ou << '-' << totsu << endl; // debug

        /* 以下 ou == 1 && totsu == 1 */
        /* rの自由度を求める (次の ou または totsu または 右端 に達するまでrを進める) */
        int dof_r = 1; // dof: degree of freedom
        while (r < N && outotsu[r - 1] == 0) {
            dof_r++;
            r++;
        }
        /* lの自由度を求める (P[l] < P[l+1] を満たしつつ、 ou または totsu を失う直前までlを進める) */
        int dof_l = P[l] < P[l + 1]; // dof: degree of freedom
        while (outotsu[l + 1] == 0) {
            if (P[l + 1] < P[l + 2]) {
                dof_l++;
            }
            l++;
        }
        // cerr << dof_l << 'x' << dof_r << endl; // debug
        ans += (long long)dof_l * dof_r;
    }
    cout << ans << endl;
    return 0;
}
/*
こういうのって尺取法でいけるんだっけ？(2025/05/23 11:39:28)
尺取法は無理だな。(2025/05/23 12:04:39)
0 -1 1 0 0 0 1 0 0
みたいな場合、
lは0,1の2通りで、rは2,3,4,5,6の5通りだからかけて10通り、みたいなのを求めていくわけだね。理屈はわかるが実装が…(2025/05/23 12:05:57)
あーA1<A2の条件忘れてた…(2025/05/23 13:06:36)
*/
/*
解説読んだ。
なるほどねえ。
*/
