#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int val[N];
bool st[N];
double res;
int n;
double area(int a,int b,int c){
    double p = (a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
} 
void dsf(int a,int b,int c,int index){
    if( a+b>c && b+c>a && a+c>b){
        res = max(area(a,b,c),res);
    }
    for(int i = index;i<=n;i++){
        if(!st[i]){
            st[i] = true;
            dsf(a + val[i],b,c,index + 1);
            dsf(a,b + val[i],c,index + 1);
            dsf(a,b,c + val[i],index + 1);
            st[i] = false;
            dsf(a,b,c,index + 1);
        }
        }
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>val[i];
    }
    dsf(0,0,0,1);
    if(res>0) printf("%.1f",res);
    else cout<<-1<<endl;
return 0;
}