// 2024/03/10 18:25:00
// 2024/03/10 18:32:03 RE
// 2024/03/10 18:33:00 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int &a: A) {
        cin >> a;
    }
    cin >> M;
    vector<int> B(M);
    for (int &b: B) {
        cin >> b;
    }
    cin >> L;
    vector<int> C(L);
    for (int &c: C) {
        cin >> c;
    }
    vector<bool> S(300000001);
    for (int a : A) {
        for (int b : B) {
            for (int c : C) {
                S[a + b + c] = true;
            }
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << (S[x] ? "Yes" : "No") << endl;
    }
    return 0;
}
/*
100 * 100 * 100 の100万通りって間に合うんだっけ？
*/
/*
普通に間に合ったわ。300万要素のvectorも生成できるし。
まあmapとか使っても良いのかも知れないけれど。unordered_map(HashMap)ならO(1)だったかな。
ユーザ解説曰く、bitsetというライブラリを使っても良い模様。なんとなく実装は想像できるな。
*/
