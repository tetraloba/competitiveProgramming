//2022/08/20 21:00:10
//2022/08/20 21:52:09 WA
//2022/08/20 22:11:12 AC.
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
/* 並べ替え用indexを生成 やり方が分からないのでゴリ押し */
void func(int arr[3], int i){
    switch (i) {
      case 0:
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;
        break;
      case 1:
        arr[0] = 0;
        arr[1] = 2;
        arr[2] = 1;
        break;
      case 2:
        arr[0] = 1;
        arr[1] = 0;
        arr[2] = 2;
        break;
      case 3:
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 0;
        break;
      case 4:
        arr[0] = 2;
        arr[1] = 0;
        arr[2] = 1;
        break;
      case 5:
        arr[0] = 2;
        arr[1] = 1;
        arr[2] = 0;
        break;
    }
    return;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend()); //降順ソート
    long long max = 0;
    for (int i = 0; i < 6; i++) {
        int arr[3];
        func(arr, i);
        string S = to_string(A[arr[0]]) + to_string(A[arr[1]]) + to_string(A[arr[2]]);
        if (max < stoll(S)) {
            max = stoll(S);
        }
    }
    cout << max << endl;
    return 0;
}
// 7, 9, 98 なら98 9 7 ではなく 9, 98, 7
// 7, 8, 98 なら勿論 98, 8, 7
// 最上位が同値なら桁が少ない方優先？
// いや997, 98なら 997, 98か。。。
// 最上位から見ていってどちらかが大きければ大きい方が先。同値なら次の位を見る。先に桁が尽きたら(0が来たら)そっちが優先？いや901とかもあるか。0では判定できない。
// 920, 90, 92, 901なら 優先度は92, 920, 90, 901か。。。
// ？？？？？違うわｗｗｗｗ 桁数多いほうが答え大きくなるのかｗｗｗ
// いや合ってるわ。どうせ３つは選ぶんだもんな。。。？え？？
// とにかく桁が大きい方が良いから、桁が大きい方優先で、同桁なら数値が大きい方優先で３つ選ぶ。後は並べ替え。
// ↑それつまり普通に降順で上位3つやろ。
// 並べ替えは３つやし全探索でええか？
// 入力は10^6までが３つやから答えlong long int でギリ足りる？ stoll()関数
// A B C
// A C B
// B A C
// B C A
// C A B
// C B A どうやって並べ替えるねん…
// 分からんから全部書く()
// とりあえず書けたが合っているか分からん 2022/08/20 21:51:17
// ほんま最悪の3WA
// 最大99999,99999,99999やから999,999,999,999,999でlliに収まるはず 9,223,372,036,854,775,807
// 99, 100, 100, 100 なら 100, 100, 100。桁優先。
// 5 1000000 99999 99999 1000000 1000000 で out of rangeエラー
// あ！セットやから同じ数字あかんわｗｗｗ
// 普通にsortすればええか・・・
// 5 1000000 99999 99999 1000000 1000000 はsortでもout of rangeやけど99999までは行けるので提出!
// 初めから大人しくsortしておけばよかった。非常に悔やまれる。