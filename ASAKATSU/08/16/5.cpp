//2022/08/16 08:19:59
//2022/08/16 08:31:43 洗濯により中断
//2022/08/16 09:18:49 一応再開
//2022/08/16 10:34:05 AC. mapの使い方分からなくてかなり手間取った。insertは更新できないんやな。operator[]が便利。
//ABC099_D - Good Grid
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, C, D[30][30];
    cin >> N >> C;
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < C; j++) {
            cin >> D[i][j];
        }
    }
    map<int, int> arr[3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp; // c[i][j]
            cin >> tmp;
            int index = (i + j + 2) % 3;
            arr[index][tmp]++; //arr[index].insert(make_pair(tmp, (arr[index].find(tmp) != arr[index].end() ? arr[index].at(tmp) + 1 : 1)));
            // cout << tmp << ':' << arr[index].at(tmp) << endl; //debug 
        }
    }

    // /* debug用出力 */
    // for (int i = 0; i < 3; i++) {
    //     cout << i << "-> ";
    //     for (const auto j : arr[i]) {
    //         cout << j.first << ':' << j.second << ' ';
    //     }
    //     cout << endl;
    // }

    int i[3];
    int diff_min = INT32_MAX;
    for (i[0] = 0; i[0] < C; i[0]++) {
        for (i[1] = 0; i[1] < C; i[1]++) {
            for (i[2] = 0; i[2] < C; i[2]++) {
                if (i[0] != i[1] && i[1] != i[2] && i[2] != i[0]) {
                    int diff[3] = {0};
                    for (int j = 0; j < 3; j++) {
                        for (const auto k : arr[j]) {
                            // cout << D[k.first - 1][i[j]] << '*' << k.second << endl; //debug
                            diff[j] += D[k.first - 1][i[j]] * k.second;
                        }
                    }
                    if (diff[0] + diff[1] + diff[2] < diff_min) {
                        diff_min = diff[0] + diff[1] + diff[2];
                    }
                }
            }
        }
    }
    cout << diff_min << endl;
    return 0;
}
// 30 P 3
// 30 29 28
// 30^3 27000