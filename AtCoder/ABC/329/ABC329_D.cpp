// 2024/03/26 14:59:17
// 2024/03/26 15:47:15 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Candidate{
    public:
        int no;
        int vote;
        Candidate();
    friend bool operator<(const Candidate& a, const Candidate& b){
        return a.vote < b.vote || (a.vote == b.vote && a.no > b.no);
    }
};
Candidate::Candidate(): vote(0){
    ;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<Candidate> C(N);
    for (int i = 0; i < N; i++) {
        C[i].no = i;
    }
    vector<int> HM(N); // hash_map的な。M[i]はCにおけるnoがiの要素のindex
    for (int i = 0; i < N; i++) {
        HM[i] = i;
    }

    vector<int> A(M);
    for (int &a : A) {
        cin >> a;
        a--;
        int tgt = HM[a];
        C[tgt].vote++;
        while (tgt) {
            if (C[tgt] < C[(tgt - 1) / 2]) {
                break;
            }
            HM[a] = (tgt - 1) / 2;
            HM[C[HM[a]].no] = tgt;
            swap(C[(tgt - 1) / 2], C[tgt]);
            tgt = (tgt - 1) / 2;
        }
        cout << C[0].no + 1 << endl;
        // /* debug */
        // for (int i = 0; i < N; i++) {
        //     cout << '(' << C[i].no << ',' << C[i].vote << ')' << ' ';
        //     int depth = i + 2;
        //     while (depth % 2 == 0) {
        //         depth /= 2;
        //         if (depth == 1) {
        //             cout << endl;
        //             break;
        //         }
        //     }
        // }
    }
    return 0;
}
/*
毎回挿入ソートするのはO(N*M)で間に合わないのか。
普通にヒープとかかなあ。(2024/03/26 15:01:28)
*/
