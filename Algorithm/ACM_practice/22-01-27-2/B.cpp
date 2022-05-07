#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll num;
cin>>num;
int one = num%10;
if(one > 4){
    num += 10-one;
}else{
    num -= one;
}
cout<<num;
system("pause");
return 0;
}