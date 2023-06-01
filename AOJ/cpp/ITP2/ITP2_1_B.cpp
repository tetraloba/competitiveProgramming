// 2022/08/13 18:18:28 TLE
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> A;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        switch (query) {
          case 0:{
            int d, x;
            cin >> d >> x;
            if (d) {
                A.insert(A.end(), x);
            } else {
                A.insert(A.begin(), x);
            }
            break;
          }
          case 1:{
            int p;
            cin >> p;
            cout << A[p] << endl;
            break;
          }
          case 2:{
            int d;
            cin >> d;
            if (d) {
                A.erase(A.end() - 1);
            } else {
                A.erase(A.begin());
            }
            break;
          }
        }
    }
    return 0;
}