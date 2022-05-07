#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int first,second,dif,n;
    cin>>first>>second>>n;
    dif = second - first;
    cout<<first+(n-1)*dif;
system("pause");
return 0;
}