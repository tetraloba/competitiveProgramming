// 2025/03/22 21:00:09
// 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    for (int i = 0; i < (N - 1) / 2; i++) {
        cout << '-';
    }
    for (int i = 0; i < 2 - N % 2; i++) {
        cout << '=';
    }
    for (int i = 0; i < (N - 1) / 2; i++) {
        cout << '-';
    }
    cout << endl;
    return 0;
}
