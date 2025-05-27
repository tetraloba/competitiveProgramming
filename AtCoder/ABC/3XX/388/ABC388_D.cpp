// 2025/02/23 15:55:56
// 2025/02/23 16:27:57 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    vector<int> receive_stones(N);
    for (int i = 0; i < N; i++) {
        if (1 <= i) {
            receive_stones[i] += receive_stones[i - 1] + 1;
        }
        if (i + A[i] + receive_stones[i] + 1 < N) {
            receive_stones[i + A[i] + receive_stones[i] + 1] -= 1;
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cerr << receive_stones[i] << ' '; // debug
    // }
    // cerr << endl; // debug

    for (int i = 0; i < N; i++) {
        cout << max(0, A[i] + receive_stones[i] - (N - 1 - i)) << ' ';
    }
    cout << endl;
    return 0;
}
/*
N人目はN-1個消費した後に貰う。
消費側に注目したほうがわかりやすいか？ (2025/02/23 15:58:50)
あー渡すのは成人だけか。。。(2025/02/23 16:00:38)
若干DP感？(2025/02/23 16:01:07)
5 0 9 3
2 1 10 4
2 0 11 4
2 0 10 5
と配っていけば良いわけだな。(2025/02/23 16:03:09)

4 6 7 2 5
0 7 8 3 6
0 4 9 4 7
0 4 7 5 8
0 4 7 4 9
自分が配るときに石を何個持っているかは，Ci + 左の石をくれる人。これってO(N)で求められるのかしら。
4 7 9 5 9

2 9 1 2 0 4 6 7 1 5
0 1 2 2 2 2 2 3 4 5 
*/
