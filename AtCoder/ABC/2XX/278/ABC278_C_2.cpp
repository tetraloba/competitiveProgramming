// 2024/03/03 21:11:51
// 2024/03/03 21:21:19 TLE
// 2024/03/03 21:29:05 AC.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    map<int, set<int>> VS;
    for (int i = 0; i < Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;
        A--; B--;
        switch (T) {
        case 1:
            VS[A].insert(B);
            break;
        case 2:
            VS[A].erase(B);
            break;
        case 3:
            if (VS[A].count(B) && VS[B].count(A)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            break;
        }
    }
    return 0;
}
/*
普通にsetとかでフォローリストを管理したらTLEなのか？
計算量計算できない… (2024/03/03 21:15:43)
vector<set<int>> VS(10^9); でREか。 (2024/03/03 21:27:34)
まあ使わないユーザ多いもんな。mapにするか？
*/
/*
解説を読んで。
なるほど。「AがBをフォローしているか」だけ検索できれば良いから、フォロー関係の順序対だけをmapで管理すればよいのか。
Aがフォローしている人一覧とかは出す必要がないからsetで管理する必要がないと。
*/
