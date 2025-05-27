// 2025/03/22 21:07:01
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> A(7);
    for (int &a : A) {
        cin >> a;
        a--;
    }
    vector<int> cnt(13);
    for (int a : A) {
        cnt[a]++;
    }
    int cnt_o2 = 0, cnt_o3 = 0;
    for (int c : cnt) {
        if (2 <= c) {
            cnt_o2++;
        }
        if (3 <= c) {
            cnt_o3++;
        }
    }
    cout << (2 <= cnt_o2 && 1 <= cnt_o3 ? "Yes" : "No") << endl;
    return 0;
}
