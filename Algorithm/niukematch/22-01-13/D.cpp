#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll res = 0;
int main(){
cin>>n;
ll ant,cnt = 0;
for(int i = 0;i<n;i++){
    cin>>ant;
    if(ant%2){
        res -= cnt*(cnt+1)/2;
        cnt = 0;
    }
    else{
        cnt++;
    }
}
res -=cnt*(cnt+1)/2;
res += n*(n+1)/2; 
cout<<res;
system("pause");
return 0;
}