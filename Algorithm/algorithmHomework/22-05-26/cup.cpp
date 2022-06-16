#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
    int res = 0;
int n;
cin>>n;
for(int i = 0;i<n;i++){
    int beg,end;
    cin>>beg>>end;
    for(int i = beg;i<=end;i++){
        mp[i]++;
        res = mp[i] > res ? mp[i]: res ;
    }
}
cout<<res<<endl;
system("pause");
return 0;
}

