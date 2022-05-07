#include<bits/stdc++.h>
using namespace std;

int main(){
string inp;
cin>>inp;
int b,e;
b = inp.find_first_not_of('a');
e = inp.find_last_not_of('a');
if(b==inp.npos&&e==inp.npos){
    cout<<"Yes";
}else if((e==inp.npos&&b!=inp.npos) || (e!=inp.npos&&b>inp.size()-e-1) ){
    cout<<"No";
}else{
    string cop = inp.substr(b,e-b+1);
    string ano = inp.substr(b,e-b+1);
    reverse(ano.begin(),ano.end());
    if(cop.compare(ano) == 0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}
    
system("pause");
return 0;
}