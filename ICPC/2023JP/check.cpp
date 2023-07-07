#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[50][50];
    int ans[50][50];
    int aw[2500][2];
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ans[i][j];
            aw[ans[i][j]][0]=i;
            aw[ans[i][j]][1]=j;
        }
    }
    int s=n/2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=n-1 && abs(aw[a[i][j]][0]-aw[a[i+1][j]][0])+abs(aw[a[i][j]][1]-aw[a[i+1][j]][1])<s){
                cout<<"No "<<a[i][j]<<" "<<a[i+1][j]<<" "<<abs(aw[a[i][j]][0]-aw[a[i+1][j]][0])+abs(aw[a[i][j]][1]-aw[a[i+1][j]][1])<<endl;
            }
            if(i!=0 && abs(aw[a[i][j]][0]-aw[a[i-1][j]][0])+abs(aw[a[i][j]][1]-aw[a[i-1][j]][1])<s){
                cout<<"No "<<a[i][j]<<" "<<a[i-1][j]<<" "<<abs(aw[a[i][j]][0]-aw[a[i-1][j]][0])+abs(aw[a[i][j]][1]-aw[a[i-1][j]][1])<<endl;
            }
            if(j!=n-1 && abs(aw[a[i][j]][0]-aw[a[i][j+1]][0])+abs(aw[a[i][j]][1]-aw[a[i][j+1]][1])<s){
                cout<<"No "<<a[i][j]<<" "<<a[i][j+1]<<" "<<abs(aw[a[i][j]][0]-aw[a[i][j+1]][0])+abs(aw[a[i][j]][1]-aw[a[i][j+1]][1])<<endl;
            }
            if(j!=0 && abs(aw[a[i][j]][0]-aw[a[i][j-1]][0])+abs(aw[a[i][j]][1]-aw[a[i][j-1]][1])<s){
                cout<<"No "<<a[i][j]<<" "<<a[i][j-1]<<" "<<abs(aw[a[i][j]][0]-aw[a[i][j-1]][0])+abs(aw[a[i][j]][1]-aw[a[i][j-1]][1])<<endl;
            }
        }
    }
    return 0;
}