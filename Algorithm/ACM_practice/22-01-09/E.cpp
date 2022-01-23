#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    double Xa,Xb,Ya,Yb;
    cin>>Xa>>Ya>>Xb>>Yb;
    double res = sqrt(pow(Xa-Xb,2)+pow(Ya-Yb,2));
    printf("%.3lf",res);
system("pause");
return 0;
}