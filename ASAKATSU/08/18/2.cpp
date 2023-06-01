//2022/08/18 07:30:55
//2022/08/18 08:20:39 WA 1つ余裕があって両方未満ならセーフなのか。普通に別関数作ってif分けして判定したほうが良さそう。
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> t(N), l(N) , r(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> l[i] >> r[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((l[i] - (t[i] <= 2 ? 0 : 1) <= l[j] + (t[j] <= 2 ? 0 : 1) && l[j] - (t[j] <= 2 ? 0 : 1) <= r[i] + (t[i] % 2 ? 0 : 1)) ||
                (l[j] - (t[j] <= 2 ? 0 : 1) <= l[i] + (t[i] <= 2 ? 0 : 1) && l[i] - (t[i] <= 2 ? 0 : 1) <= r[j] + (t[j] % 2 ? 0 : 1))) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}