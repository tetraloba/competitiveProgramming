//2022/08/24 07:49:34
//2022/08/24 08:12:46 TLE
#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>& A, int N, vector<int>& P, vector<int>& Q){
    if (!N) {
        return;
    }
    vector<int> L, R;
    vector<int> PL, PR;
    vector<int> QL, QR;
    int X = N / 2;
    for (int i = 0; i < N; i++) {
        if (i != X) {
            if (A[i] < A[X]) {
                L.push_back(A[i]);
                PL.push_back(P[i]);
                QL.push_back(Q[i]);
            } else {
                R.push_back(A[i]);
                PR.push_back(P[i]);
                QR.push_back(Q[i]);
            }
        }
    }
    quickSort(L, L.size(), PL, QL);
    quickSort(R, R.size(), PR, QR);
    L.push_back(A[X]);
    PL.push_back(P[X]);
    QL.push_back(Q[X]);
    L.insert(L.end(), R.begin(), R.end());
    PL.insert(PL.end(), PR.begin(), PR.end());
    QL.insert(QL.end(), QR.begin(), QR.end());
    A = L;
    P = PL;
    Q = QL;
    return;
}
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N), sum(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        sum[i] = A[i] + B[i];
    }
    quickSort(sum, N, A, B);
    // for (int i = 0; i < N; i++) {
    //     cout << sum[i] << ' ' << A[i] << ' ' << B[i] << endl;
    // }
    long long sumTKHS = 0, sumAOK = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sumTKHS += *A.rbegin();
            // cout << sumTKHS << ' ' << *A.rbegin() << endl;
        } else {
            sumAOK += *B.rbegin();
            // cout << sumAOK << ' ' << *B.rbegin() << endl;
        }
        A.pop_back();
        B.pop_back();
    }
    cout << sumTKHS - sumAOK << endl;
    return 0;
}
//若干考察要素。和が大きいやつを選ぶのでは駄目？
//和の降順に選ぶとして、和に合わせてA[i]とB[i]ソートする必要がある？2022/08/24 07:52:13
//あー昇順でソートしちゃった。まあえっか。reverseもしない。 2022/08/24 08:05:22
//TLEじゃねーか(笑) ソートする問題じゃねーな。