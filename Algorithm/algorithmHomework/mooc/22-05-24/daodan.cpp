#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std; 

int arr[33];
int dp[33];
int minN = INT32_MAX;
int ans = 0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(i == 0){
            dp[i] = 1;
            minN = arr[i];
        }else if(arr[i] <= minN){
            dp[i] = dp[i-1] + 1;
            ans = max(ans,dp[i]);
            minN = arr[i];
        }else{
            int j = i-1;
            while(j >= 0 && arr[j] < arr[i]){
                j--;
            }
            if(j == -1){
                dp[i] = 1;
            }else{
                dp[i] = dp[j] + 1;
                ans = max(ans,dp[i]);
            }
            minN = arr[i];
    }
}
    printf("%d", ans);
    system("pause");
}