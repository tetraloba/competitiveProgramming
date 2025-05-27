// 2023/07/12 20:42:06
// 2023/07/12 20:51:16 AC.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string S;
    cin >> S;
    int cnt_rear = 0;
    for (int i = S.length() - 1; 0 <= i; i--) {
        if (S[i] != 'a') {
            break;
        }
        cnt_rear++;
    }
    int cnt_front = 0;
    for (char s : S) {
        if (s != 'a') {
            break;
        }
        cnt_front++;
    }

    string S2 = "";
    for (int i = 0; i < cnt_rear - cnt_front; i++) {
        S2 += 'a';
    }
    S2 += S;

    int front = 0, rear = S2.length() - 1;
    cerr << S2 << endl;
    while (front < rear) {
        if (S2[front] != S2[rear]) {
            cout << "No" << endl;
            return 0;
        }
        front++;
        rear--;
    }
    cout << "Yes" << endl;
    return 0;
}