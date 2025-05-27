//2022/08/13 09:51:35
//2022/08/13 10:12:36 TLE, RE
//↑一度探索してfalseだったところを重複して探索していた(l22,28で解消)のと、終端文字(0)分の余分な配列を確保するのを忘れていた。
//2022/08/13 10:22:25 AC.
#include <iostream>
using namespace std;
int diff(int A, int B){
    if (A < B) {
        return B - A;
    }
    return A - B;
}
bool func(int A0, int* A, int* B, int K){
    // cout << A0 << ':' << A[1] << ',' << B[1] << endl; //debug
    bool flag = false;
    if (!(*(A + 1))) {
        return true;
    }
    if (diff(A0, *(A + 1)) <= K) {
        flag = func(*(A + 1), A + 1, B + 1, K);
        if (!flag) {
            *(A + 1) = -K; //以降ずっとfalse
        }
    }
    if (!flag && diff(A0, *(B + 1)) <= K) {
        flag = func(*(B + 1), A + 1, B + 1, K);
        if (!flag) {
            *(B + 1) = -K; //以降ずっとfalse
        }
    }
    return flag;
}
int main(){
    int N, K, A[200001] = {0}, B[200001] = {0};
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    if (func(A[0], A, B, K) || func(B[0], A, B, K)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}