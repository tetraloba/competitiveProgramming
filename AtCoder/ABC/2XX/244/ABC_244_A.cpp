#include <iostream>
using namespace std;
int main(){
    int N;
    char S[1000]; //要素数1001にしたほうが良いか。このプログラムに関してはこれでも動くけど。配列外にNULL文字入れているからアウトだよな。
    cin >> N >> S;
    cout << S[N - 1] << '\n';
    return 0;
}