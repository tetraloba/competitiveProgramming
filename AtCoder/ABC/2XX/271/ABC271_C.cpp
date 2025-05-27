// 2023/06/15 21:28:47
// 2023/06/15 22:09:01 WA
// 2023/06/15 22:14:04 WA
// 2023/06/15 22:20:28 WA
// 2023/06/15 22:23:34 AC.
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    set<int> st;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    vector<int> a(st.begin(), st.end());
    int buyNum = N - st.size();
    int readNumber = 1;
    int i = 0;
    bool flag = true;
    while (true) {
        // cerr << "readNumber:i:size:buyNum = " << readNumber << ':' << i << ':' << a.size() << ':' << buyNum << endl;
        if (flag && readNumber == a[i]) {
            i++;
            if (a.size() <= i) {
                flag = false;
            }
        } else if (2 <= buyNum) {
            buyNum -= 2;
        } else if (buyNum && i < a.size()) {
            buyNum = 0;
            a.pop_back();
            if (a.size() <= i) {
                flag = false;
            }
        } else if (i + 1 < a.size()) {
            a.pop_back();
            a.pop_back();
            if (a.size() <= i) {
                flag = false;
            }
        } else {
            readNumber--;
            break;
        }
        readNumber++;
    }
    cout << readNumber << endl;
    return 0;
}
// 12345
// 1
// 11 1 1 1 1 1 1 1 1 1 1 6
// 11 1 1 1 1 1 1 1 1 1 1 1
// 11 1 1 1 1 1 1 1 1 1 1 7
// 1(2345)7
// 1