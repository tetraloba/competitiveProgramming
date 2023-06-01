//2022/08/10 07:40:56
//2022/08/10 07:49:40 TLE
//2022/08/10 08:06:24 AC.
#include <iostream>
#include <iomanip>
#include <set>
using namespace std;
int main(){
    int NA, NB;
    set<int> A;
    cin >> NA >> NB;
    int cnt1 = 0, tmp;
    for (int i = 0; i < NA; i++) {
        cin >> tmp;
        A.insert(tmp);
    }
    for (int i = 0; i < NB; i++) {
        cin >> tmp;
        if (A.count(tmp)) {
            cnt1++;
        }
    }
    cout << fixed << (double)cnt1 / (NA + NB - cnt1) << endl;
    return 0;
}
//set使わないとTLEかな？