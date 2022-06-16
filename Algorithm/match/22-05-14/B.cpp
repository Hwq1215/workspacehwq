#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
 
int arr[1001];
int dp[5000060];
int main(){
int ans = 0;
int n,w;
cin>>n>>w;
for(int i = 0;i<n;i++){
    int val;
    cin>>val;
    arr[i] = val;
    dp[val] = 1;
}
 
//two and three
for(int i = 0;i<n-2;i++){
    for(int j = i+1;j<n;j++){
        int val = arr[i]+arr[j];
        dp[val] = 1;
        for(int u = j+1;u<n;u++){
            dp[val + arr[u]] = 1;
        }   
    }
}
 
if(n >= 2) dp[arr[n-2] + arr[n-1]] = 1;

//check
for(int i = 1;i<=w;i++){
    if(dp[i]!=0){
        ans++;
    }
}

cout<<ans;
system("pause");
return 0;
}