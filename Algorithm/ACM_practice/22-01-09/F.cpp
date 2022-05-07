#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
double x,a,b,c,d;
cin>>x>>a>>b>>c>>d;
printf("%.7lf",a*pow(x,3) + b*pow(x,2) + c*x + d);
system("pause");
return 0;
}