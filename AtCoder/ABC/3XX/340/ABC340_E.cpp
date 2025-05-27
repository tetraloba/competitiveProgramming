// 2024/04/15 19:50:35
// 2024/04/15 21:02:38 セグ木か。無理ですね。
#include <iostream>
#include <vector>
#define dist(s, d) ((d + N - s - 1) % N + 1)
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int &a : A) {
        cin >> a;
    }
    for (int &b : B) {
        cin >> b;
    }
    int x = 4;
    int ball = A[x];
    for (int i = 0; i < N; i++) {
        A[i] = ball / N + (dist(x, i) <= ball % N ? 1 : 0);
    }
    for (int a : A) {
        cout << a << ' ';
    }
    cout << endl;
    // cout <<  << endl;
    return 0;
}
/*
0 1 2 3 4
1 2 3 4 5
2 2 0 5 6
4 3 1 6 1
0 4 2 7 2

-4 1 1 1 1
-4 0 -2 5 1
3 -1 -2 5 -5
-2 4 -2 5 -5


x i
d = dist(i, x)
A[i] / N + A[i] % N / d

0 1 2 3 4
3 2 1 5 4 (3+5-x)
8 7 6 5 4 (-1)
7 6 5 4 3 (%5)
2 1 0 4 3 (+1)
3 2 1 5 4

2024/04/15 20:34
0 1 2 3 4
1 2 3 4 5

0 -1 0 1 0
2 2 0 5 6

4 3 1 6 1
0 4 2 7 2

変化だけの情報に落とし込めばO(4 * M)くらいになりそうっていうのは分かるんだけどね。(2024/04/15 20:43:25)

*/
