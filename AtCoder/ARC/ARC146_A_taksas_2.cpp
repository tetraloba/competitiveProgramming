// ARC146 - A
// REALTIME
// rnd
// SHOULD?


// -----     cpp_snippets_v8.2     -----
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <ctime>
#include <functional>
#include <stack>
#include <queue>
#include <tuple>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <sstream>


#define rep(i,n)                for (int i = 0; i < n; i++)
#define vrep(X)                 for (auto&& x : X)

#define vvii(X,n1,n2)           vector<vector<int>> X(n1,vector<int>(n2))

#define bgen(X)                 begin(X), end(X)
#define coutd(X)                cout << X << endl
#define coutds(N,X)             cout << fixed << setprecision(N) << X << endl
#define chmax(X1, X2)           X1 = max(X1, X2)
#define chmin(X1, X2)           X1 = min(X1, X2)
#define nextP(X)                next_permutation(X.begin(), X.end())

#define INF                     1e18
#define ll                      long long int


using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i,N) cin >> A[i];
    sort(bgen(A));

    vector<pair<int,int>> ans(3);
    rep(i,3) {
        ans[i].second = A[N-1-i];
        int tempi = A[N-1-i];
        int temp =  to_string(A[N-1-i]).length();
        rep(j,temp-1) {
            tempi /= 10;
        }
        ans[i].first = tempi;
    }
    sort(bgen(ans));
    ll truans = 0;
    vector<int> ansnext(3);
    rep(i,3) {
        ansnext[i] = ans[2-i].second;
        // coutd(ansnext[i]);
    }
    do {
        string temp = "";
        rep(j,3) {
            temp += to_string(ansnext[j]);
            
        }
        istringstream ss = istringstream(temp);
        ll num; ss >> num;
        truans = max(truans, num);
    } while(nextP(ansnext));
    coutd(truans);
    
    
    
    return 0;
    
}