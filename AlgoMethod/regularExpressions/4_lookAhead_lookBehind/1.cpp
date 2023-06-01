//2022/08/19 20:48:10
//2022/08/19 21:11:47 わからんから解説見た。
#include <iostream>
#include <regex>
using namespace std;
int main(){
    string S;
    cin >> S;
    regex reg{R"(?<=r)u(?=r)"};
    string T = "a";
    S = regex_replace(S, reg, T);
    cout << S << endl;
    return 0;
}