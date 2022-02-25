#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x;
scanf("%lld",&x);
    long long f = x;
    long long flag = x%10;
    x /= 10;
if(x<=0&&flag!=0&&f<0) x = x-1;
printf("%lld",x);
system("pause");
return 0;
}
