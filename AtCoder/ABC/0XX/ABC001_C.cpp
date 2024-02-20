// 2024/02/20 20:46:40
// 2024/02/20 21:13:18 WA
// 2024/02/20 21:17:16 WA 1
// 2024/02/20 21:31:29 AC.
#include <iostream>
#include <vector>
#define MAX_DIS 12000
using namespace std;
int main(){
    char* deg_arr[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "N"};
    int dis_arr[] = {2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326, MAX_DIS * 100 / 60 / 10};
    int Deg, Dis;

    cin >> Deg;
    char* Dir = deg_arr[(Deg * 10 + 1125) * 16 / 36000];

    cin >> Dis; // < 12000
    Dis = Dis * 100 / 60; // < 20000
    Dis = Dis % 10 < 5 ? Dis / 10 : Dis / 10 + 1; // 四捨五入して10で割る // < 2000
    int W = 0;
    while (dis_arr[W] < Dis) W++;

    if (W == 0) Dir = "C"; // Wが0なら風向はC

    cout << Dir << ' ' << W << endl;
    return 0;
}