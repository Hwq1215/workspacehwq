#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        int message;
        cin>>message;
        cnt += message%70? message/70+1:message/70;
    }
    printf("%.1f",0.1*cnt);
system("pause");
return 0;
} 