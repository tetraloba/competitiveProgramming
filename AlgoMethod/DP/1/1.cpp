#include <iostream>
#include <utility> //for swap()
using namespace std;
int main(){
    int N, X, Y;
    cin >> N >> X >> Y; // N > 3
    for (int i = 0; i < N - 2; i++) {
        X = (X + Y) % 100;
        swap(X, Y);
    }
    cout << Y << endl;
    return 0;
}