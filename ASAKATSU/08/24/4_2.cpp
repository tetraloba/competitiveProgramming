//2022/08/24 07:49:34
//2022/08/24 08:12:46 TLE
//2022/08/24 09:14:59 TLE 知ってた。
#include <iostream>
#include <vector>
using namespace std;
struct hoge3{
    int A;
    int B;
    int sum;
};
void quickSort(vector<hoge3>& A, int N){
    if (!N) {
        return;
    }
    vector<hoge3> L, R;
    int X = N / 2;
    for (int i = 0; i < N; i++) {
        if (i != X) {
            if (A[i].sum < A[X].sum) {
                L.push_back(A[i]);
            } else {
                R.push_back(A[i]);
            }
        }
    }
    quickSort(L, L.size());
    quickSort(R, R.size());
    L.push_back(A[X]);
    L.insert(L.end(), R.begin(), R.end());
    A = L;
    return;
}
int main(){
    int N;
    cin >> N;
    vector<hoge3> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].A >> v[i].B;
        v[i].sum = v[i].A + v[i].B;
    }
    quickSort(v, N);
    // for (int i = 0; i < N; i++) {
    //     cout << sum[i] << ' ' << A[i] << ' ' << B[i] << endl;
    // }
    long long sumTKHS = 0, sumAOK = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sumTKHS += v.rbegin()->A;
            // cout << sumTKHS << ' ' << *A.rbegin() << endl;
        } else {
            sumAOK += v.rbegin()->B;
            // cout << sumAOK << ' ' << *B.rbegin() << endl;
        }
        v.pop_back();
    }
    cout << sumTKHS - sumAOK << endl;
    return 0;
}
//若干考察要素。和が大きいやつを選ぶのでは駄目？
//和の降順に選ぶとして、和に合わせてA[i]とB[i]ソートする必要がある？2022/08/24 07:52:13
//あー昇順でソートしちゃった。まあえっか。reverseもしない。 2022/08/24 08:05:22
//TLEじゃねーか(笑) ソートする問題じゃねーな。
//いや、構造体で定数倍早くすればまだ舞える・・・？