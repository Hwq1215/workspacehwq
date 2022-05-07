#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
map<int,int> noodles;
for(int i = 0;i<n;i++){
    int c;
    cin>>c;
    noodles[c]++;
}
for(int i = 0;i<m;i++){
    int c;
    cin>>c;
    noodles[c]--;
    if(noodles[c]<0){
        cout<<"No";
        system("pause");
        return 0;
    }
}
cout<<"Yes";
system("pause");
return 0;
}
