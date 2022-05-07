#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int m,n,x;
cin>>m>>n>>x;
while(n<=m){
    int val = m/n;
    if(m%n) x -= val + 1;
    else x -= val;
    if(x < 0) break;
    n += val;
}
cout<<n;
return 0;
}       