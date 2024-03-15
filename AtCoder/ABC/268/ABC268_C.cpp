// 2024/03/15 17:57:02
// 2024/03/15 18:06:12 AC.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    for (int &p_e : p) {
        cin >> p_e;
    }
    vector<int> happy(N);
    for (int i = 0; i < N; i++) {
        int exp_num = ((i + N) - p[i]) % N;
        happy[exp_num]++;
        exp_num = (exp_num + N - 1) % N;
        happy[exp_num]++;
        exp_num = (exp_num + 2) % N;
        happy[exp_num]++;
    }
    cout << *max_element(happy.begin(), happy.end()) << endl;
    return 0;
}
/*
各人が喜ぶ回転数を求めれば良さそう。(2024/03/15 18:00:48)
*/
