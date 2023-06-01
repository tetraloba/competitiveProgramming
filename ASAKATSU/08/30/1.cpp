//2022/08/30 07:30:08
//2022/08/30 08:16:05 WA あー同じ点数のやつか。=>いや、Aiは相異なるわ。
//2022/08/30 08:38:52 AC. reverse iteratorを間違っていた気がする。↑1WAなのおかしくね？
//ABC213_B - Booby Prize
#include <iostream>
#include <map>
using namespace std;
int main(){
    int N;
    cin >> N;
    map<int, int> A;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        A.insert(make_pair(tmp, i));
    }
    auto itr = A.rbegin();
    itr++;
    cout << itr->second << endl;
    return 0;
}