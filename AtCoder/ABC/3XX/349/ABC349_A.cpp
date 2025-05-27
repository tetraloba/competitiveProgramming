// 2024/04/13 21:00:08
// 2024/04/13 21:01:38 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N - 1);
    for (int &a : A) {
        cin >> a;
    }
    int sum = 0;
    for (int a : A) {
        sum += a;
    }
    cout << 0 - sum << endl;
    return 0;
}
