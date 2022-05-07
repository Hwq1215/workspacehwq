#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
char c;
cin>>c;
for(int i = -2;i<3;i++){
    for(int k = 0;k<abs(i);k++) cout<<" ";
    for(int j = 0;j<5-2*abs(i);j++) cout<<c;
    cout<<endl;
}
system("pause");
return 0;
}