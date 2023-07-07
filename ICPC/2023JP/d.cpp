#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int bool p[110]={};
    for(int i=1;i<=100;i++){
        for(int j=0;j<=n-1;j++){
            if(p[j] && j!=i  && j+i<=100){
                p[j+i]=true;
            }
        }
    }
    while(1) {
        int n,ans=0;
        string s;
        cin>>n;
        if(!n){
            break;
        }
        cin>>s;
        p[0]=true;
        for(int i=1;i<s.size();i++){
            if(s[i]=='o' && !p[i]){
                ans++;
                for(int j=0;j<=n;j++){
                    if(p[j] && j!=i  && j+i<=100){
                        p[j+i]=true;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}