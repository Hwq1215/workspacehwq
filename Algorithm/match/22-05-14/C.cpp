
#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> m;
int maxN = 0;
int ans = 1;
int main(){
int n;
cin>>n;

for(int i = 1 ;i<=n; i++){
    string s;
    int t;
    cin>>s;
    cin>>t;
    if( !m.count(s) ){
        if(t>maxN){
            ans = i;
            maxN = t;
        }
        m[s] = t;
    } 
}

cout<<ans<<endl;
system("pause");
return 0;
}