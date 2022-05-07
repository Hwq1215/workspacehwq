//浮点二分模板题
#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int MAXN = 1e5+6;
int n,f;
double a[MAXN];

bool condition(double val){
    int num = 0;
    for(int i = 0;i<n;i++){
        num += a[i]/val;
    }
    return num >= f+1;
}
int main(){
    double left = 0,right = 0;
    cin>>n>>f;
    for(int i = 0;i<n;i++){
        double v;
        cin>>v;
        a[i] = v*v*pi;
        right = max(right,a[i]);
    }
    while(right - left>1e-5){
        double mid = (right + left)/2;
        if(condition(mid)){
            left = mid;
        }else{
            right = mid;
        } 
    }
    printf("%.3f",right);
system("pause");
return 0;
}
