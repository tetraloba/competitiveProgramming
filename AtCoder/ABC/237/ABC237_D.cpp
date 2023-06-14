// 2023/06/14 17:18:18
// 2023/06/14 17:41:44 AC.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void printDequeI(deque<int>& D){
    for (int i : D) {
        cout << i << ' ';
    }
    cout << endl;
}
int main(){
    int N;
    string S;
    cin >> N >> S;
    deque<int> D;
    D.push_back(N);
    for (int i = N - 1; 0 <= i; i--) {
        if (S[i] == 'L') {
            D.push_back(i);
        } else {
            D.push_front(i);
        }
        // printDequeI(D);
    }

    printDequeI(D);
    return 0;
}
// 0123456789