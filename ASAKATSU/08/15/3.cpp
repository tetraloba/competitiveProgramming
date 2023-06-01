//2022/08/15 07:45:26
//2022/08/15 08:39:33 AC.
//ABC213_C - ReorderCards
#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
    int H, W, N, A[100000], B[100000];
    cin >> H >> W >> N;
    set<int> dH, dW; //dirty
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        dH.insert(A[i]);
        dW.insert(B[i]);
    }
    map<int,int> mH;
    int cnt = 1;
    for (int i : dH) {
        mH.insert(make_pair(i, cnt));
        cnt++;
    }
    map<int,int> mW;
    cnt = 1;
    for (int i : dW) {
        mW.insert(make_pair(i, cnt));
        cnt++;
    }
    for (int i = 0; i < N; i++) {
        cout << mH.at(A[i]) << ' ' << mW.at(B[i]) << endl;
    }
    return 0;
}
