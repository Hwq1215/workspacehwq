#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
string str_a,str_b;
cin>>str_a>>str_b;
for(char &c:str_a){
    if(c >= 'a') c -= 32;
}
for(char &m:str_b){
    if(m >= 'a') m -= 32;
}
if(str_a.compare(str_b)>0) cout<<">";
else if(str_a.compare(str_b)<0) cout<<"<";
else cout<<"=";
system("pause");
return 0;
}