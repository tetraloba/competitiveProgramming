// 2025/03/10 21:35:19
// 2025/03/10 21:52:02 7WA
// 2025/03/10 21:52:53 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> memo;
long long f(long long N){
    if (N == 0) {
        return 1;
    }
    long long a1 = memo[N / 2], a2 = memo[N / 3];
    if (!a1) {
        a1 = f(N / 2);
    }
    if (!a2) {
        a2 = f(N / 3);
    }
    memo[N] = a1 + a2;
    return a1 + a2;
}
int main(){
    long long N;
    cin >> N;
    cout << f(N) << endl;
    return 0;
}
/*
1 2 3 4 5 5 7 7 8 9 9 9 12 12 12 12 13 13 16 16 16 16 16 16 20 20 20 21 21 21 21 21 22 22 22 22 28 28 28 28 28 28 28 28 28 28 28 28 33 33 33 33 33 33 37 37 37 37 37 37 37 37 37 37 38 38 38 38 38 38 38 38 48 48 48 48 48 48 48 48 48 49 49 49 49 49 49 49 49 49 49 49 49 49 49 49 55 55 55 55 
メモ化再帰書いてみるか？(2025/03/10 21:42:10)
*/
