// 2023/11/04 22:30:02
// 2023/11/04 22:57:45 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> A(M);
    vector<string> S(N);
    for (int i = 0; i < M; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    /* 各プレイヤの総合得点をscoresに格納 */
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        scores[i] += i + 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
                scores[i] += A[j].first;
            }
        }
    }

    /* 問題の得点を高い順にソート */
    sort(A.rbegin(), A.rend());
    
    int max_score = *max_element(scores.begin(), scores.end()); // 現時点の最高得点
    for (int i = 0; i < N; i++) {
        int score = scores[i];
        unsigned int cnt = 0;
        for (pair<int, int> a : A) {
            if (max_score <= score) {
                break;
            }
            if (S[i][a.second] == 'x') {
                score += a.first;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}