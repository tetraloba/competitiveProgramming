// 2025/03/01 12:02:46
// 2025/03/01 12:38:50 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
struct Pos{
    ll x;
    ll y;
};
struct House{
    Pos pos;
    bool done;
};
int main(){
    int N, M;
    Pos S;
    cin >> N >> M >> S.x >> S.y;
    vector<House> houses(N);
    map<ll, map<ll, House*>> x_houses, y_houses;
    for (House &house: houses) {
        cin >> house.pos.x >> house.pos.y;
        house.done = false;
        x_houses[house.pos.x][house.pos.y] = &house;
        y_houses[house.pos.y][house.pos.x] = &house;
    }

    for (int i = 0; i < M; i++) {
        char d;
        int c;
        cin >> d >> c;
        typename map<ll, House*>::iterator itr_l, itr_r;
        switch (d) {
            case 'U':
                itr_l = x_houses[S.x].lower_bound(S.y);
                S.y += c;
                itr_r = x_houses[S.x].upper_bound(S.y);
                while (itr_l != itr_r) {
                    (*itr_l).second->done = true;
                    itr_l++;
                }
                break;
            case 'D':
                itr_r = x_houses[S.x].upper_bound(S.y);
                S.y -= c;
                itr_l = x_houses[S.x].lower_bound(S.y);
                while (itr_l != itr_r) {
                    (*itr_l).second->done = true;
                    itr_l++;
                }
                break;
            case 'L':
                itr_r = y_houses[S.y].upper_bound(S.x);
                S.x -= c;
                itr_l = y_houses[S.y].lower_bound(S.x);
                while (itr_l != itr_r) {
                    (*itr_l).second->done = true;
                    itr_l++;
                }
                break;
            case 'R':
                itr_l = y_houses[S.y].lower_bound(S.x);
                S.x += c;
                itr_r = y_houses[S.y].upper_bound(S.x);
                while (itr_l != itr_r) {
                    (*itr_l).second->done = true;
                    itr_l++;
                }
                break;
        }
    }

    int ans = 0;
    for (House house : houses) {
        ans += house.done;
    }
    cout << S.x << ' ' << S.y << ' ' << ans << endl;
    return 0;
}
/*
ある点と点の間に有る家の判定か・・・(2025/03/01 12:04:36)
行ごと，列ごとの家のリストを作ってニブタンするんじゃ駄目なのかね？(2025/03/01 12:05:41)
*/
