// ARC124_B - XOR Matching 2
// 2024/12/08 07:36:49
// 2024/12/08 07:59:19 AC.
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    set<int> ans;
    for (int i = 0; i < N; i++) {
        int x = A[0] ^ B[i];
        map<int, int> mp;
        for (int j = 0; j < N; j++) {
            mp[B[j]]++;
        }
        mp[B[i]]--;
        bool flag = true;
        for (int j = 1; j < N; j++) {
            if (mp[(A[j] ^ x)] == 0) {
                flag = false;
                break;
            }
            mp[(A[j] ^ x)]--;
        }
        if (flag) {
            ans.insert(x);
        }
    }
    cout << ans.size() << endl;
    for (int a : ans) {
        cout << a << endl;
    }
    return 0;
}
/*
組み合わせ全探索だと2000C2 間に合うのか…？2000!か？？？(2024/12/08 07:40:19)
いやx列挙だから無理か。(2024/12/08 07:40:57)
XORは逆算できるか。(2024/12/08 07:51:03)
1つ目を2000通り考えて、それぞれについてxを計算して対応するやつが有るか探せば良いから
O(N * N * log(N))でいけるか。(2024/12/08 07:52:17)
*/
