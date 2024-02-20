// 2024/02/20 20:46:40
// 2024/02/20 21:13:18 WA
// 2024/02/20 21:17:16 WA 1
// 2024/02/20 21:31:29 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int Deg, Dis;

    cin >> Deg;
    char* deg_arr[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    char* Dir = deg_arr[(Deg * 10 + 1125) * 16 / 36000];

    cin >> Dis;
    Dis = Dis * 100 / 60;
    Dis = Dis % 10 < 5 ? Dis / 10 : Dis / 10 + 1; // 四捨五入
    int dis_arr[] = {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326};
    int W = -1;
    for (int i = 0; i < 12; i++) {
        if (Dis <= dis_arr[i]) {
            W = i;
            break;
        }
    }
    if (W == -1) W = 12;

    if (W == 0) Dir = "C"; // Wが0なら風向はC

    cout << Dir << ' ' << W << endl;
    return 0;
}