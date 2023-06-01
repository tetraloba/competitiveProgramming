//2022/08/20 13:40:24
//2022/08/20 13:59:39 WA いつものオーバーフロー？
//2022/08/20 14:01:42 WA ?????
//2022/08/20 14:09:08 AC. 永久にreturn時のキャスト忘れるマン。。。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    cout << (long long)(0 <= N - 2 ? N - 2 : 2 - N) * (0 <= M - 2 ? M - 2 : 2 - M) << endl;
    return 0;
}