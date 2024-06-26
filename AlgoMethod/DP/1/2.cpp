﻿// 
// 2022/08/12 13:55:59 AC (提出履歴より)
#include <iostream>
#include <vector>
#include <algorithm> // for min()
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    A[0] = 0;
    A[1] = A[1];
    for (int i = 2; i < N; i++) {
        A[i] = min(A[i - 2] + A[i] * 2, + A[i - 1] + A[i]);
    }
    cout << A[N - 1] << endl;
    return 0;
}
/*
2024/04/12 13:12:48
貰うDPという実装になるらしい。
https://algo-method.com/descriptions/78
*/
