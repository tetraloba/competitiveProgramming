// 2023/06/01 20:50:51
// 2023/06/01 21:12:57 AC.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> stu(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        stu[A].insert(B);
        stu[B].insert(A);
    }

    vector<pair<int,int>> friendNum(N);
    for (int i = 0; i < N; i++) {
        friendNum[i] = make_pair(i, stu[i].size());
    }
    sort(friendNum.begin(), friendNum.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    for (int i : stu[friendNum[0].first]) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}