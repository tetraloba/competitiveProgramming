//2022/09/06 10:03:24
//
#include <iostream>
#include <vector>
using namespace std;
bool find(vector<int>& v, int n){
    auto itr = v.begin();
    bool flag = false;
    while (itr != v.end()) {
        if (*itr++ == n) {
            flag = true;
        }
    }
    return flag;
}
int main(){
    int N, A, B;
    cin >> N >> A >> B;
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        int tmpN = S.size();
        for (int j = 0; j < tmpN; j++) {
            if (S[j] == 'o') {
                v[i].push_back(j);
            }
        }
    }
    // for (int i = 0; i < N; i++) { //debug
    //     int tmpN = v[i].size();
    //     for (int j = 0; j < tmpN; j++) {
    //         cout << v[i][j] << (j != tmpN - 1 ? ' ' : '\n');
    //     }
    // }
    cout << (find(v[A], B) ? "Yes" : "No") << endl;
    return 0;
}