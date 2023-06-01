//2022/08/25 08:17:33
//
#include <iostream>
#include <vector>
using namespace std;
dict[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int func(int hoge[][50], int i, int j){
    for (int d = 0; d < 4; d++) {
        hoge[i + dict[d][0]][j + dict[d][1]];
    }
    if (hoge[i][j])
}
int main(){
    int H, W;
    cin >> H >> W;
    int hoge[50][50];
    ;
    cout <<  << endl;
    return 0;
}
// ゴールできるかだけ判定してH * W - (H + W - 1) - #
// クソ簡単やけどゴールできるかの判定方法知らん。2022/08/25 08:19:52
// あー順番に何通りの行き方があるか数字振っていくやつか。算数や。
// と言っても手前からやらないといけないのか。どうする？再帰行ける？
// 最短コースがH + W - 2とは限らないからH * W - (最短経路 + 1) - #ってところか。 2022/08/25 08:30:26