#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int dp[1005][1005];
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i = 1;i<=m;i++){
        dp[i][1] = 1;
    }
    for(int i = 1;i<=n;i++){
        dp[1][i] = 1;
    }
    for(int i = 2;i<=m;i++){
        for(int j = 2;j<=n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    printf("%d",dp[m][n]);
system("pause");
return 0;
}