#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int last = 2;
    int i,j,flag = 1;
    for(i = 3;i<=n;i++){
        for(j = 2;j<=i/2+1;j++){
            if(i%j == 0) break;
        }
        if(j == i/2+2){
            if(i - last == 2){
                cout<<last<<" "<<i<<endl;
                flag = 0;}
            last = i;
        }
    }
    if(flag) cout<<"empty";
system("pause");
return 0;
}