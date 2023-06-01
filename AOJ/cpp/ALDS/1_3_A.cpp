//2022/08/11 19:49:44
//2022/08/11 21:56:23
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
void calc(vector<int>::iterator itr, char oprtr) {
    itr--; //最後の要素を指す
    int num1 = *itr;
    int num2 = *--itr;
    if (oprtr == '+') {
        *itr = num2 + num1;
    } else if (oprtr == '-') {
        *itr = num2 - num1;
    } else {
        *itr = num2 * num1;
    }
}
int main(){
    vector<int> v;
    char tmp;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string s;
    while (getline(ss, s, ' ')) {
        if ('0' <= s[0] && s[0] <= '9') {
            v.insert(v.end(), atoi(s.c_str()));
        } else {
            calc(v.end(), s[0]);
            v.erase(v.end() - 1);
        }
    }
    cout << v[0] << endl;
    return 0;
}