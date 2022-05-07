#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
bool has = false;
vector<bool> boom(n+1,false);
for(int i = 2;i<=m;i++){
    for(int j = 1;j<=n;j++){ 
        if(j%i == 0){
            boom[j] = !boom[j];
            }
    }
}
for(int i = 1;i<=n;i++){
    if(boom[i] == false){
        if(has) cout<<",";
        cout<<i;
        has = true;
    } 
}
system("pause");
return 0;
}


