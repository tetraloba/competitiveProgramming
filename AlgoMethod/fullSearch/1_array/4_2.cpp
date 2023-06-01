//2022/08/11 17:39:15
//2022/08/11 17:58:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, V;
    cin >> N >> V;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.insert(A.end(), tmp);
    }
    auto itr = A.end();
    itr--;
    // cout << "itr:" << *itr << endl;
    int ans = N - 1;
    for (int i = 0; i < N; i++) {
        // cout << *itr << endl;
        if (*itr == V) {
            break;
        }
        itr--;
        ans--;
    }
    cout << ans << endl;
    return 0;
}