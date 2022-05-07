#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1>>n2;
    string t1[n1];
    string inp;
    for(int i = 0;i<n1;i++){
        cin>>t1[i];
    }
    int j = 0;
    for(int i = 0;i<n1;i++){
        if(i==0) cin>>inp;
        if(inp==t1[i]){
            cout<<"Yes"<<endl;
            j++;
            if(j<n2)cin>>inp;
        }else{
            cout<<"No"<<endl;
        }
    }
system("pause");
return 0;
}