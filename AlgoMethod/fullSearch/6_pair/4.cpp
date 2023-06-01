//2022/08/15 13:55:45
//2022/08/15 14:00:28 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] == S[j]) {
                flag = true;
            }
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}