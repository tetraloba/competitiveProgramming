//2022/10/13 10:00:40
//2022/10/13 10:04:15 AC.
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> st;
    for (int i = 0; i < 5; i++) {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }
    cout << st.size() << endl;
    return 0;
}