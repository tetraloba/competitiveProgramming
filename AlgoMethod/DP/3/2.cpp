// 2024/04/14 15:42:56
// 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> done;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> W(N);
    for (int &w : W) {
        cin >> w;
    }
    done = *new vector<bool>(M);
    sort(W.begin(), W.end());
    vector<vector<int>> dp(N, vector<int>(M));
    for ()
    cout <<  << endl;
    free(&done);
    return 0;
}
/*
メモ化再帰で解けそうだけど。(2024/04/14 15:53:06)
*/
