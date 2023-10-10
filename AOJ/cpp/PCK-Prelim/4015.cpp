// 2023/10/06 19:44:05
// 
#include <iostream>
#include <vector>
using namespace std;
int abs(int a, int b){
    return a < b ? b - a : a - b;
}
int main(){
    vector<pair<int, int>> vp(4, make_pair(0, 0));
    for (int i = 0; i < 4; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    cout << (abs(vp[0].first, vp[2].first) == abs(vp[0].second, vp[2].second) && ((vp[0].first == vp[3].first && vp[1].first == vp[2].first && vp[0].second == vp[1].second && vp[2].second == vp[3].second) || (vp[0].first == vp[1].first && vp[2].first == vp[3].first && vp[0].second == vp[3].second && vp[1].second == vp[2].second)) ? "Yes" : "No") << endl;
    return 0;
}
