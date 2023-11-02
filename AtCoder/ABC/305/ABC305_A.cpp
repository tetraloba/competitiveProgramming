// 2023/11/02 23:13:43
// 2023/11/02 23:19:33 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    cout << (N - N / 5 * 5 < (N / 5 + 1) * 5 - N ? N / 5 * 5 : (N / 5 + 1) * 5) << endl;
    return 0;
}