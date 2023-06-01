//2022/08/28 07:33:14
//2022/08/28 07:36:40 AC.
//ABC019_B - 高橋くんと文字列圧縮
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int N = s.size();
    for (int i = 0; i < N; i++) {
        char c = s[i];
        int cnt = 0;
        while (s[i] == c) {
            cnt++;
            i++;
        }
        i--;
        cout << c << cnt;
    }
    cout << endl;
    return 0;
}