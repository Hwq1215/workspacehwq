#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll f[10][3];
int main(){
    ll cnt[10];
    f[0][1] = 0;
    f[0][2] = 0;
    for(int i = 1;i<10;i++){
        cin>>cnt[i];
    }
    for(int i = 0;i<10;i++){
        f[i][0] = 1;
    }
    for(int i = 1;i<10;i++){
        int sum1 = 0,sum2 = 0,sum0 = 0;
        if(i%3 == 1){
            sum1 = (cnt[i]+2)/3;
            sum2 = (cnt[i]+1)/3;
            sum0 =  cnt[i]/3;
        }
        else if(i%3 == 2){
            sum1 = (cnt[i]+1)/3;
            sum2 = (cnt[i]+2)/3;
            sum0 = cnt[i]/3;
        }
        else{
            sum1 = 0,sum2 = 0,sum0 =cnt[i];
        }
        f[i][0] = f[i-1][0] * (sum0 + 1) + sum2 * f[i-1][1] + sum1 * f[i-1][2];
        f[i][1] = f[i-1][1] + f[i-1][0] * sum1 + f[i-1][2] * sum2 + f[i-1][1] * sum0;
        f[i][2] = f[i-1][2] + f[i-1][0] * sum2 + f[i-1][2] * sum0 + f[i-1][1] * sum1;
        f[i][0] %= mod;
        f[i][1] %= mod;
        f[i][2] %= mod;
    }
    cout<<f[9][0]<<endl;
system("pause");
return 0;
}