#include <iostream>
using namespace std;
int main(){
    char S[101], tgt[] = "algo";
    cin >> S;
    for (int i = 0; S[i]; i++) {
        int k = i;
        int flag = 1;
        for (int j = 0; tgt[j]; j++, k++) {
            if (S[k] != tgt[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}