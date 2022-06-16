#include<bits/stdc++.h>
using namespace std;

int main(){
string s;
cin>>s;
string n = s;
if(n.size()>3) return 0;
while(n.size() != 6){
    n.append(s);
}
cout<<n;
system("pause");
return 0;
}