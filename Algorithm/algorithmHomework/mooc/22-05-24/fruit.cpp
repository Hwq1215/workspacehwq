#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){

string str_a,str_b ,str_res;
cin>>str_a>>str_b;
int len_a = str_a.length(),len_b = str_b.length();
int len_min = min(len_a,len_b);
int i = 0,j = 0;
while(i != str_a.size() && j != str_b.size()){
    if(str_a[i] == str_b[j]){
        str_res += str_a[i];
        i++;
        j++;
    }else{
        str_res += str_a[i];
        i++;
    }
}
str_res += str_b.substr(j,len_b - j);
cout<<str_res;
system("pause");
return 0;
}