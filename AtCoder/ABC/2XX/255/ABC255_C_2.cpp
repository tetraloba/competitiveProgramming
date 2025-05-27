//2022/08/19 10:29:48
//2022/08/19 11:27:23 WA
//2022/08/19 11:33:36 AC. エグいて…
#include <iostream>
using namespace std;
long long diff(long long a, long long b){
    if (a < b) {
        return b - a;
    }
    return a - b;
}
int main(){
    long long X, A, D, N;
    cin >> X >> A >> D >> N;
    long long ans;
    if (diff(X, A) <= diff(X, A + D) || N == 1) {
        ans = diff(X, A);
    } else if (diff(X, A + D * (N - 1)) <= diff(X, A + D * (N - 2))) {
        ans = diff(X, A + D * (N - 1));
    } else {
        ans = min(diff(X, A + D * ((X - A) / D)), diff(X, A + D * ((X - A) / D + 1)));
    }
    cout << ans << endl;
    return 0;
}