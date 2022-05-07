#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e4;
int cost[maxN][maxN];
int dp[maxN]; //记录1到其他点的最少租金

int minCost(int n){
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            cin>>cost[i][j];
            if(i == 1){
                dp[j] = cost[i][j];
        }
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            dp[j] = min(dp[j],dp[i] + cost[i][j]);   //更新dp
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int res = minCost(n);
    cout<<res;
system("pause");
return 0;
}