// 2023/05/26 23:28:32
// 2023/05/26 23:30:37
#include <iostream>
#include <vector>
using namespace std;
int main(){
    string tgt[5] = {"and", "not", "that", "the", "you"};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++) {
            if (str == tgt[j]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}