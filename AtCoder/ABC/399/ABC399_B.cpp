// 2025/03/29 21:00:58
// 2025/03/29 21:09:21 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    map<int, int> score;
    for (int a : A) {
        score[a]++;
    }
    map<int, int> rank;
    int r = 1;
    for (auto itr = score.rbegin(); itr != score.rend(); itr++) {
        rank[itr->first] = r;
        r += itr->second;
    }
    for (int i = 0; i < N; i++) {
        cout << rank[A[i]] << endl;
    }
    return 0;
}
