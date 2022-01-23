#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int val[n+1];
    if(n==1){
        cout<<1;
    }
    for(int i = 1;i<=n;i++){
        val[i] = 4;
    }
    for(int i = 0;i<4*n-1;i++){
        int m;
        cin>>m;
        val[m]--;
    }
    for(int i = 1;i<=n;i++){
        if(val[i]){
            cout<<i;
            break;
        }
    }
return 0;
}