#include<bits/stdc++.h>
using namespace std;

int main(){
    int length,pos;
scanf("%d%d",&length,&pos);
string str;
cin>>str;
string front = str.substr(0,pos);
str = str.substr(pos,str.size());
str.append(front);
cout<<str;
system("pause");
return 0;
}