// 2024/02/15 23:06:12
// 2024/02/15 23:16:56 RE
// 2024/02/15 23:24:42 AC.
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int value;
    Node *next;
};
int main(){
    int N;
    cin >> N;
    vector<int> Ans(N + 1);
    int tgt; // 先頭
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1) {
            Ans[0] = i;
            tgt = i;
        } else {
            Ans[tmp] = i;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << tgt << ' ';
        tgt = Ans[tgt];
    }
    cout << endl;
    return 0;
}