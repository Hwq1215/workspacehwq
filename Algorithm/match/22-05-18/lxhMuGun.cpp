#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    double m,n;
    cin>>m>>n;
    double res = pow((sqrt(m) + sqrt(n)),6);
    ll temp = (ll) res;
    if(res - temp>0){
        cout<<temp+1<<endl;
    }
    else{
        cout<<temp<<endl;
    }
system("pause");
return 0;
}