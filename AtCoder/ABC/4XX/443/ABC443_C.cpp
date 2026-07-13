// 2026/07/13 13:06:12
// 2026/07/13 13:12:19 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int &a : A) {
        cin >> a;
    }

    A.push_back(T); // sentinel
    int ans = 0;
    int chokutter_open_time = 0;
    for (int a : A) {
        if (a < chokutter_open_time) {
            continue;
        }
        int chokutter_close_time = a;
        ans += chokutter_close_time - chokutter_open_time;
        chokutter_open_time = chokutter_close_time + 100;
    }
    cout << ans << endl;
    return 0;
}
