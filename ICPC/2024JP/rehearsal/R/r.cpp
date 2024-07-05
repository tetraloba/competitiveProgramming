#include <iostream>
#include <vector>
using namespace std;
int main(){
    while (true) {
        int N;
        cin >> N;
        if (!N) {
            return 0;
        }
        vector<int> V(N);
        for (int &v : V) {
            cin >> v;
        }
        int cnt = 0;
        for (int i = 1; i < N - 1; i++) {
            if (V[i - 1] < V[i] && V[i + 1] < V[i]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
