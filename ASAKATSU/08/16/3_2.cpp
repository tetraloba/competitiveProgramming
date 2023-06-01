//2022/08/16 07:47:23
//2022/08/16 07:52:41 TLE
//2022/08/16 08:09:50 WA
//2022/08/16 08:16:47 AC. またオーバーフロー…
//ABC171_D -Replacing
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q, B, C;
    cin >> N;
    vector<int> A(N);
    long long int sum = 0;
    int num[100000] = {0};
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        num[tmp - 1]++;
        sum += tmp;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> B >> C;
        sum += (C - B) * num[B - 1];
        num[C - 1] += num[B - 1];
        num[B - 1] = 0;
        cout << sum << endl;
    }
    return 0;
}