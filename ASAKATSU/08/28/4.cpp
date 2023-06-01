//2022/08/28 07:38:19
//2022/08/28 07:51:57 AC.
//ARC042_A - 掲示板
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++) {
        a[i] = make_pair(0, i + 1);
    }
    for (int i = -1; -M <= i; i--) {
        int tmp;
        cin >> tmp;
        a[tmp - 1].first = i;
    }
    sort(a.begin(), a.end());
    for (pair<int, int> i : a) {
        cout << i.second << endl;
    }
    return 0;
}
//毎回並び替えたらTLE?