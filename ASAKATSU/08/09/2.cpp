//2022/08/09 07:32:09
//2022/08/09 08:29:38 無理だろ
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main(){
    int N;
    set<long long int> st;
    cin >> N;
    for (int i = 2; i <= pow(N, 0.5); i++) {
        for (int j = i; j <= N; j++) {
            long long int tmp = pow((long long)i, j);
            cout << tmp << endl;
            if (N < tmp) {
                break;
            } else {
                st.insert(tmp);
            }
        }
    }
    cout << N - st.size() << '\n';
    return 0;
}