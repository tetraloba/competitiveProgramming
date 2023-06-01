//2022/08/15 14:01:19
//2022/08/15 14:02:32 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] == S[j]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}