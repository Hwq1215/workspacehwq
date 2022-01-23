#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int n,a_num,b_num;
cin>>n>>a_num>>b_num;
int a[a_num],b[b_num];
for(int i = 0 ;i<a_num;i++){
    cin>>a[i];
}
for(int i = 0;i<b_num;i++){
    cin>>b[i];
}
int a_win = 0,b_win = 0;
for(int i = 0;i<n;i++){
    if((a[i%a_num]==0&&b[i%b_num]==2) || (a[i%a_num]==2&&b[i%b_num]==5) ||(a[i%a_num]==5&&b[i%b_num]==0)){
        a_win++;
    }else if((a[i%a_num]==2&&b[i%b_num]==0) || (a[i%a_num]==5&&b[i%b_num]==2) ||(a[i%a_num]==0&&b[i%b_num]==5)){
        b_win++;
    }
}
if(a_win  == b_win){
    cout<<"draw";
}else if(a_win > b_win){
    cout<<"A";
}else{
    cout<<"B";
}
system("pause");
return 0;
}