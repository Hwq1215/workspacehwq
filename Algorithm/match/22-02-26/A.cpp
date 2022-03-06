#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10];
    for(int i = 0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int num = a[0];
    for(int index = 0;index<2;index++){
        num = a[num]; 
    }
    cout<<num;
system("pause");
return 0;
}