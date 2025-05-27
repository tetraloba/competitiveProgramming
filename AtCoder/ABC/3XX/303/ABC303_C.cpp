// 2023/10/30 11:15:11
// 2023/10/30 12:15:42 AC.
#include <iostream>
#include <set>
using namespace std;
struct Pos{
    int x;
    int y;

    bool operator<(const Pos& other) const {
        // cout << "call <" << endl;
        // cout << "compare (" << x << ',' << y << ") (" << other.x << ',' << other.y << ')' << endl;
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
    bool operator==(const Pos& other) const {
        // cout << "call ==" << endl;
        return x == other.x && y == other.y;
    }
    bool operator>(const Pos& other) const {
        // cout << "call >" << endl;
        if (x == other.x) {
            return y > other.y;
        }
        return x > other.x;
    }
};

int main(){
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<Pos> care_pos;
    for (int i = 0; i < M; i++) {
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        care_pos.insert(Pos{tmp_x, tmp_y});
    }
    Pos takahashi = {0, 0};
    for (char s : S) {
        switch (s) {
            case 'R':
                takahashi.x += 1;
                break;
            case 'L':
                takahashi.x -= 1;
                break;
            case 'U':
                takahashi.y += 1;
                break;
            case 'D':
                takahashi.y -= 1;
                break;
        }
        if (--H < 0) {
            cout << "No" << endl;
            return 0;
        }
        auto st_itr = care_pos.find(Pos{takahashi.x, takahashi.y});
        // cout << st_itr->x << st_itr->y << endl;
        if (st_itr != care_pos.end() && H < K) {
            care_pos.erase(st_itr);
            H = K;
        }
        // cout << takahashi.x << ',' << takahashi.y << ':' << H << endl;
    }
    cout << "Yes" << endl;
    return 0;
}