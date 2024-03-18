// 2024/03/18 18:28:03
// 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool is_square_number(long long N) {
    long long cand = pow(N, 0.5);
    if (cand * cand == N) {
        return true;
    }
    cand++;
    if (cand * cand == N) {
        return true;
    }
    return false;
}
int main(){
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    long long ans = 0;
    do {
        if (is_square_number(stoll(S))) {
            ans++;
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << ans << endl;
    return 0;
}
/*
next_permutation()するとO(13!)で間に合わないのか。
平方数が高々10^7しか無いので、それぞれSの並び替えで作れるかを判定すれば良いか。
*/
