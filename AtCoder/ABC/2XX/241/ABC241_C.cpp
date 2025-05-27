// 2024/02/25 13:39:02
// 2024/02/25 13:56:45 WA
// 2024/02/25 14:10:58 AC.
#include <iostream>
#include <vector>
using namespace std;
int N;
bool inMatrix(int h, int w){
    return 0 <= h && h < N && 0 <= w && w < N;
}
int main(){
    const int K = 6;
    cin >> N;
    vector<string> S(N);
    for (string &s : S) {
        cin >> s;
    }

    // pair<int, int> DIR8[8] = {make_pair(0, 1), make_pair(-1, 1), make_pair(-1, 0), make_pair(-1, -1),
    //                           make_pair(0, -1), make_pair(1, -1), make_pair(1, 0), make_pair(1, 1)};
    // pair<int, int> DIR4of8[4] = {make_pair(0, 1), make_pair(-1, 1), make_pair(-1, 0), make_pair(-1, -1)};
    pair<int, int> DIR4of8[4] = {{0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
    const int D = 4;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < D; d++) {
                int cnt = 0;
                if (!inMatrix(i + DIR4of8[d].first * (K - 1), j + DIR4of8[d].second * (K - 1))) {
                    continue;
                }
                for (int k = 0; k < K; k++) {
                    cnt += S[i + DIR4of8[d].first * k][j + DIR4of8[d].second * k] == '.';
                }
                if (cnt <= 2) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}