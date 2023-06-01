//2022/08/14 07:31:13
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    set<int> s;
    for (int i = 0; i < K; i++) {
        s.insert(c[i]);
    }
    int max = s.size();
    for (int i = K; i < N; i++) {
        if ()
    }
    cout <<  << endl;
    return 0;
}