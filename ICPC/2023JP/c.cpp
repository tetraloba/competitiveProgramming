#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n;
    int a[50][50];
    int ans[50][50];
    while(1){
    cin >> n;
    if(!n){
        break;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int h,w;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(n%2==0){
                ans[i][j] = a[i/2+(n/2)*((i+1)%2)][j];
            }else{
                ans[i][j] = a[i/2+(n/2)*(i%2)][j];
            }            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(n%2==0){
                a[i][j] = ans[i][j/2+(n/2)*((j+1)%2)];
            }else{
                a[i][j] = ans[i][j/2+(n/2)*(j%2)];
            }                     
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    }
    return 0;
}