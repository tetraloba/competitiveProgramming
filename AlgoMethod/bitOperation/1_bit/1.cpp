//2022/08/16 11:03:32
//2022/08/16 11:05:07 コード書く問題じゃなかったわｗｗｗ
#include <iostream>
using namespace std;
int main(){
    string S;
    cin >> S;
    int N = S.size();
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}