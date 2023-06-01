#include <iostream>
using namespace std;
void lotate(int*);
int main(){
    int N, R[4] = {0}, r = 0;
    char T;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T;
        if (T == 'R') {
            lotate(&r);
        } else {
            R[r]++;
        }
    }
    cout << R[0] - R[2] << ' ' << R[3] - R[1] << '\n';
    return 0;
}
void lotate(int *r){
    if (*r < 3) {
        (*r)++;
    } else {
        *r = 0;
    }
}