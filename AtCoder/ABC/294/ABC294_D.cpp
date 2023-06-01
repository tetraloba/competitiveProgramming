//2023/05/14 08:07:38
//2023/05/14 08:33:13 TLE. リストの線形探索は無理か…vectorで両サイドから詰めていくとかの方が速いだろうな。
#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // find()
using namespace std;
int main(){
    int N, Q;
    cin >> N >> Q;
    list<int> wait, called;
    for (int i = 1; i <= N; i++) {
        wait.push_back(i);
    }
    for (int i = 0; i < Q; i++) {
        int eve, who;
        cin >> eve;
        switch (eve) {
          case 1:
            called.push_back(*wait.begin());
            wait.pop_front();
            break;
          case 2:
            cin >> who;
            called.erase(find(called.begin(), called.end(), who));
            break;
          case 3:
            cout << *called.begin() << endl;
            break;
        }
        /* debug */
        // cout << "wait: ";
        // for (int e : wait) {
        //     cout << e << ' ';
        // }
        // cout << endl;
        // cout << "called: ";
        // for (int e : called) {
        //     cout << e << ' ';
        // }
        // cout << endl;
    }
    return 0;
}