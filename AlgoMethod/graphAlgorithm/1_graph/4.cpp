// 2023/06/01 21:18:23
// 2023/06/01 21:42:21 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, M, X;
    cin >> N >> M >> X;
    vector<set<int>> stu(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        stu[A].insert(B);
        stu[B].insert(A);
    }

    set<int> fof;
    for (int i : stu[X]) {
        fof.insert(stu[i].begin(), stu[i].end());
    }

    fof.erase(X);
    for (int i : stu[X]) {
        if (fof.find(i) != fof.end()) {
            fof.erase(i);
        }
    }
    
    cout << fof.size() << endl;
    return 0;
}