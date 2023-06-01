//2022-08-04 08:01:55
//
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
    }
    return 0;
}
//1.各頂点から繋がっている頂点の配列を作る。
//2.選べる頂点のsetを作る。
//3.頂点1から繋がっている頂点配列の要素をsetに追加する。
//4.setの最小値を選び、ans配列に追加する。
//5.選んだ頂点の配列をsetに追加し、選んだ頂点をsetから削除する。
//6.4に戻る
//以上 2022-08-04 08:12:54