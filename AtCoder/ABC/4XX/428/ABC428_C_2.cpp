// 2025/12/12 21:45:30
// 2025/12/12 23:44:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Q;
    cin >> Q;

    vector<int> S(1); // i文字目までの '('の数 - ')'の数
    int minus_cnt = 0; // S内の負の値の数
    for (int q = 0; q < Q; q++) {
        // for (int s : S) {
        //     cerr << s << ' ';
        // }
        // cerr << endl;
        int qn;
        char c;
        cin >> qn;
        switch (qn) {
            case 1:
                cin >> c;
                S.push_back(S.back() + (c == '(' ? 1 : -1));
                if (S.back() < 0) {
                    minus_cnt++;
                }
                cout << (S.back() || minus_cnt ? "No" : "Yes") << endl;
                break;
            case 2:
                if (S.back() < 0) {
                    minus_cnt--;
                }
                S.pop_back();
                cout << (S.back() || minus_cnt ? "No" : "Yes") << endl;
                break;
        }
    }
    return 0;
}
/*
*/

