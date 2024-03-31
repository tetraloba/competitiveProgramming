// 2024/04/01 07:30:07
// 2024/04/01 07:32:36 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    map<int ,int> cnt;
    for (int a : A) {
        cnt[a]++;
    }
    for (int b : B) {
        if (!cnt[b]) {
            cout << "No" << endl;
            return 0;
        }
        cnt[b]--;
    }
    cout << "Yes" << endl;
    return 0;
}
