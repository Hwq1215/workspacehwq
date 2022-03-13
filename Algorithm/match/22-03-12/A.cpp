#include<bits/stdc++.h>
using namespace std;

int main(){
int t,a,b,c;
scanf("%d%d%d%d",&t,&a,&b,&c);
int sum = a + b + c;
int res = t%sum;
if(res<a){
    cout<<"F";
}else if(res<a + b){
    cout<<"M";
}else{
    cout<<"T";
}
system("pause");
return 0;
}