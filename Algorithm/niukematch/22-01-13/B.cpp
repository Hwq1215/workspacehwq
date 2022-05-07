#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
    int total;
    cin>>total;
    for(int k = 0;k<total;k++){
        ll a,b,target;
        cin>>a>>b>>target;
        if(a==target||b==target) {
            cout<<0<<endl;
            continue;
        }
        if(target%2) cout<<-1<<endl;
        else{
            int cnt = 1;
            ll sum = a+b;
            if(sum<target){
                long double c = log2l(target*1.0/sum);
                cnt = (int)log2l(target*1.0/sum);
                cnt = c-cnt>0? (int)log2l(target*1.0/sum)+1:(int)log2l(target*1.0/sum);
            }
            cout<<cnt<<endl;
        }
    }
return 0;
}