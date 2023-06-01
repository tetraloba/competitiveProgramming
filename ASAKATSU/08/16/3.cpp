//2022/08/16 07:47:23
//2022/08/16 07:52:41
//ABC171_D -Replacing
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, Q, B, C;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> B >> C;
        int dif = C - B;
        for (int i = 0; i < N; i++) {
            if (A[i] == B) {
                A[i] = C;
                sum += dif;
            }
        }
        cout << sum << endl;
    }
    return 0;
}