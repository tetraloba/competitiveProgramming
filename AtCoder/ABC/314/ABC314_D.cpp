// 2024/02/29 19:46:11
// 2024/02/29 20:00:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> ut(N); // update time
    char up_or_lo = 'n';
    int ul_time = -1;
    for (int i = 0; i < Q; i++) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        switch (t) {
            case 1:
                S[x - 1] = c;
                ut[x - 1] = i;
                break;
            case 2:
                up_or_lo = 'l';
                ul_time = i;
                break;
            case 3:
                up_or_lo = 'u';
                ul_time = i;
                break;
        }
    }
    switch (up_or_lo) {
        case 'n':
            break;
        case 'l':
            for (int i = 0; i < N; i++) {
                if (ut[i] < ul_time) {
                    S[i] = tolower(S[i]);
                }
            }
            break;
        case 'u':
            for (int i = 0; i < N; i++) {
                if (ut[i] < ul_time) {
                    S[i] = toupper(S[i]);
                }
            }
            break;
    }
    cout << S << endl;
    return 0;
}