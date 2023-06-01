#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <functional>
#include <tuple>
#include <sstream>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<long long> A{0, 0, 0};
    for (int i = 0; i < N; i++) {
        long long temp;
        cin >> temp;
        for (int j = 0, j < 3; j++) {
            if(A[j] < temp) {
                A[j] = temp;
                break;
            }
        }
        sort(A.begin(), A.end());
    }
 
    long long truans = 0;
    do {
        string temp = to_string(A[0]) + to_string(A[1]) + to_string(A[2]);
        istringstream ss = istringstream(temp);
        long long num;
        ss >> num;
        truans = max(truans, num);
    } while(next_permutation(A.begin(), A.end()));
    cout << truans << endl;
    return 0;
}