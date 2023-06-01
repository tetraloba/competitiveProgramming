//2022/08/06 21:07:30
//2022/08/06 21:20:26
#include <iostream>
using namespace std;
void func(int *P, int N, int *cnt){
    (*cnt)++;
    if (P[N] != 1) {
        func(P, P[N] - 1, cnt);
    } else {
        return;
    }
}
int main(){
    int N, P[49], cnt = 0;
    cin >> N;
    P[0] = 1;
    for (int i = 1; i < N; i++) {
        cin >> P[i];
    }
    func(P, N - 1, &cnt);
    cout << cnt << endl;
    return 0;
}
// 1 1 2