#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
for(int i = 0;i<n;i++){
    string str;
    cin>>str;
    if(str.size()>2&&str[str.size()-2]=='A'&&str[str.size()-1]=='K'){
        cout<<str.substr(0,str.size()-2);
        return 0;
    }
}
return 0;
}