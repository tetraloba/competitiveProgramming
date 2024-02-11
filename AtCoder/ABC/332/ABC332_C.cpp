// 2024/02/11 14:40:35
// 2024/02/11 14:52:18 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    string S;
    cin >> N >> M >> S;
    int ans = 0; // ロゴの総数
    int muji = M; // 着用可能な無地
    int logo = 0; // 着用可能なロゴ
    for (char c : S) {
        switch (c) {
          case '0':
            muji = M; // 無地をすべて洗濯
            logo = ans; // ロゴをすべて洗濯
            break;
          case '1':
            if (0 < muji) {
                muji--; // 無地を一枚消費
                break;
            }
          case '2':
            if (0 < logo) {
                logo--; // ロゴを一枚消費
            } else {
                ans++; // ロゴを一枚購入
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}