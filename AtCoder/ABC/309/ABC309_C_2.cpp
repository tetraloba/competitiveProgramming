// 2024/03/28 14:52:43
// 2024/03/28 15:02:08 8WA
// 2024/03/28 15:07:08 AC.
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    long long sum = 0; // 1日の薬の数
    map<int, long long> mp; // mp[i]==n : i日目は前日に比べてn錠減る
    mp[1] = 0; // 初日は全ての薬を飲む
    for (int i = 0; i < N; i++) {
        mp[a[i] + 1] += b[i]; // a日間b錠飲む -> a+1日目にb錠減る
        sum += b[i];
    }

    for (auto [k, v] : mp) {
        sum -= v;
        if (sum <= K) {
            cout << k << endl;
            return 0;
        }
    }
    return 0;
}
/*
Nの制約が優しいのでNをkeyにしたmapを作りそうな雰囲気は有る。
薬の種類が減る日だけを探索していけばよい。
もっと高速化も出来そうだけれど。
どうせ境界値でWA (2024/03/28 15:01:49)
*/
