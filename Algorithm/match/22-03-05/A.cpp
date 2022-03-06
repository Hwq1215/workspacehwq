#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double ans = 1;
    if(d>a&&d<=b){
        ans = c*1.0/(b-a);
    }else if(d>b){
        ans = 0.0;
    }
    printf("%.12f",ans);
system("pause");
return 0;
}