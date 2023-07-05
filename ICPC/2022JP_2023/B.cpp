// 2023/07/05 20:30:36
// 2023/07/05 21:11:36 セグフォ
#include <iostream>
#include <vector>
#include <limits>
using namespace std;
void swap(int& a, int& b){
    a ^= b;
    b ^= a;
    a ^= b;
}
// min <= a <= b にするbubble sort的なやつ。
int sorttekinayatsu(int& a, int& b, int& min){
    if (a == std::numeric_limits<int>::max()){
        return 0;
    }
    if (b < a) {
        swap(a, b);
    }
    if (min < a) {
        return 1;
    }
    swap(a, min);
    if (b < a) {
        swap(a, b);
    }
    return 1;
}
void next(int& i, int n){
    i++;
    if (i == n) {
        i = 0;
    }
}
int solve(int n){
    vector<int> c1, c2;
    for (int i = 0; i < n; i++) {
        cin >> c1[i] >> c2[i];
    }
    int min;
    int ans = 0;
    int cnt_death = 0;
    int i = 0;
    while (true) {
        if (c1[i] == min) {
            min = c2[i];
            c1[i] = c2[i] = std::numeric_limits<int>::max();
            cnt_death++;
        } else if (c2[i] == min) {
            min = c1[i];
            c1[i] = c2[i] = std::numeric_limits<int>::max();
            cnt_death++;
        }
        ans += sorttekinayatsu(c1[i], c2[i], min);
        next(i, n);
        if (cnt_death == n) {
            break;
        }
    }
    return ans;
}
int main(){
    while (true) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        cout << solve(n) << endl;
    }
    return 0;
}