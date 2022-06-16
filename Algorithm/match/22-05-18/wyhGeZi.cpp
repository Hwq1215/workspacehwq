#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll n;
    cin>>n;
    for(int i = 0;i<n;i++){
        ll m,n;
        cin>>m>>n;
        ll N = min(m,n);
        ll res = N*m*n 
                - (m + n)* (N-1) *N  /2 
                + (N - 1)* N * (2*N-1)/6;
        cout<<res<<endl;
    }
system("pause");
return 0;
}