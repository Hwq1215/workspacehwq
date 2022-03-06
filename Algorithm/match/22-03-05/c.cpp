#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll length = (ll)1000004;
ll dp[length][11];
int main(){
    ll mod = (ll)998244353;
    int n;
    cin>>n;
    for(int i = 1;i<10;i++){
        dp[1][i] = 1;
    }
    for(int i = 2;i<=n;i++){
        dp[i][1] = (dp[i-1][1] + dp[i-1][2])%mod;
        dp[i][2] = ((dp[i-1][2] + dp[i-1][1])%mod + dp[i-1][3])%mod;
        dp[i][3] = ((dp[i-1][3] + dp[i-1][2])%mod + dp[i-1][4])%mod;
        dp[i][4] = ((dp[i-1][4] + dp[i-1][3])%mod + dp[i-1][5])%mod;
        dp[i][5] = ((dp[i-1][5] + dp[i-1][4])%mod + dp[i-1][6])%mod;
        dp[i][6] = ((dp[i-1][6] + dp[i-1][5])%mod + dp[i-1][7])%mod;
        dp[i][7] = ((dp[i-1][7] + dp[i-1][6])%mod + dp[i-1][8])%mod;
        dp[i][8] = ((dp[i-1][8] + dp[i-1][7])%mod + dp[i-1][9])%mod;
        dp[i][9] = (dp[i-1][8] + dp[i-1][9])%mod;
    }
    ll ans = 0;
    for(int i = 1;i<10;i++){
        ans = (ans+dp[n][i])%mod;
    }
    cout<<ans;
system("pause");
return 0;
}