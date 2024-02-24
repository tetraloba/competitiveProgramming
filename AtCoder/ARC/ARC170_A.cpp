// 2024/02/24 21:04:55
// 2024/02/24 21:15:55 WA
// 2024/02/24 21:37:18 WA
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<int> replace(N);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' && T[i] == 'B') {
            replace[i] = 1;
        } else if (S[i] == 'B' && T[i] == 'A') {
            replace[i] = -1;
        }
    }
    // -1, 0, 1, -1, 1 => O
    // 1, -1 => X
    // 一番左(0を除く)が-1で一番右が1ならOK?
    // 違うな。1より左にAが有って-1より右にBが有れば良い。
    bool left_A = true, right_B = true;
    for (int i = 0; i < N; i++) {
        if (T[i] == 'A') {
            break;
        }
        if (replace[i] == 1) {
            left_A = false;
            break;
        }
    }
    for (int i = N - 1; 0 <= i; i--) {
        if (T[i] == 'B') {
            break;
        }
        if (replace[i] == -1) {
            right_B = false;
            break;
        }
    }
    if (!left_A || !right_B) {
        cout << -1 << endl;
        return 0;
    }

    // 回数は-1と1の多い方
    int cnt_AtoB = 0, cnt_BtoA = 0;
    for (int i = 0; i < N; i++) {
        if (replace[i] == 1) {
            cnt_AtoB++;
        } else if (replace[i] == -1) {
            cnt_BtoA++;
        }
    }
    cout << max(cnt_AtoB, cnt_BtoA) << endl;
    return 0;
}

// BAA
// ABA
// AAB

// BBA -> AAB
// ABA
// AAB

// BAABA -> ABBAB
// ABABA
// ABAAB
// ABBAB

// BAAAAAABA
// ABAAAAABA
// ABAAAAAAB
// ABBAAAAAB
// ABBBAAAAB
// ABBBBAAAB
// ABBBBBAAB
// ABBBBBBAB

// BBBBBA
// ABBBBB
// AABBBB
// AAABBB
// AAAABB
// AAAAAB

// ABB
// AAB

// ABBBBB
// AAAAAB

// AAA
// ABA

// AAA
// BBA X

// BAA
// BBA X
