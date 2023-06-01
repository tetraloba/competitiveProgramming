//2022/08/13 17:56:43
//2022/08/13 18:04:41 AC.
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
          case 0:
            int x;
            cin >> x;
            A.insert(A.end(), x);
            break;
          case 1:
            int p;
            cin >> p;
            cout << A[p] << endl;
            break;
          case 2:
            A.erase(A.end() - 1);
            break;
        }
    }
    return 0;
}