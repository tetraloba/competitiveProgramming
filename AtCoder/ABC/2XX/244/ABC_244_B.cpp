#include <iostream>
using namespace std;
void lotate(int*);
int main(){
    int N, R[4], r; //これRとr初期化しないと駄目だよな？このまま通ったが？(笑)
    char T[100001];
    cin >> N >> T;
    for (int i = 0; T[i]; i++) {
        if (T[i] == 'R') {
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