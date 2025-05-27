// 2025/04/27 09:06:41
// 2025/04/27 10:03:00 AC.
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Query {
    int index;
    int L, R;
    int X;
    int lcount, rcount;
};
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }
    int Q;
    cin >> Q;
    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        queries[i].index = i;
        cin >> queries[i].L >> queries[i].R >> queries[i].X;
        queries[i].L--; queries[i].R--;
    }
    vector<Query*> qs_sortL, qs_sortR;
    for (int i = 0; i < Q; i++) {
        qs_sortL.push_back(&queries[i]);
        qs_sortR.push_back(&queries[i]);
    }
    sort(qs_sortL.begin(), qs_sortL.end(), [](auto const& lhs, auto const& rhs) {
        return lhs->L < rhs->L;
    });
    sort(qs_sortR.begin(), qs_sortR.end(), [](auto const& lhs, auto const& rhs) {
        return lhs->R < rhs->R;
    });
    /* debug */
    // for (int i = 0; i < Q; i++) {
    //     auto e = *qs_sortL[i];
    //     cerr << '(' << e.L << ',' << e.R << ',' << e.X << ')' << ' ';
    // }
    // cerr << endl;
    // for (int i = 0; i < Q; i++) {
    //     auto e = *qs_sortR[i];
    //     cerr << '(' << e.L << ',' << e.R << ',' << e.X << ')' << ' ';
    // }
    // cerr << endl;

    auto itrL = qs_sortL.begin(), itrR = qs_sortR.begin();
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        // cerr << i << ':';
        // cerr << "L:";
        while (itrL != qs_sortL.end() && (*itrL)->L == i) {
            (*itrL)->lcount = cnt[(*itrL)->X];
            // cerr << (*itrL)->index << '=' << cnt[(*itrL)->X] << ' ';
            itrL++;
        }
        cnt[A[i]]++;
        // cerr << "R:";
        while (itrR != qs_sortR.end() && (*itrR)->R == i) {
            (*itrR)->rcount = cnt[(*itrR)->X];
            // cerr << (*itrR)->index << '=' << cnt[(*itrR)->X] << ' ';
            itrR++;
        }
        // cerr << endl;
    }
    for (auto q : queries) {
        // cerr << q.lcount << ' ' << q.rcount << endl; // debug
        cout << q.rcount - q.lcount << endl;
    }
    return 0;
}
/*
クエリ先読み(2025/04/27 09:08:52)
*/
/*
うーん、想定解ではなさそうか。
解説読んでください。
*/
