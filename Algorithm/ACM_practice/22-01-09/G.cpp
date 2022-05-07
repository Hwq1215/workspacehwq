#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
int n,cnt_1 = 0 ,cnt_5 = 0 ,cnt_10 = 0;
cin>>n;
for(int i = 0;i<n;i++){
    int num;
    cin>>num;
    if(num == 1) cnt_1++;
    else if(num == 5) cnt_5++;
    else if(num == 10) cnt_10++;
}
cout<<cnt_1<<endl
    <<cnt_5<<endl
    <<cnt_10<<endl;
system("pause");
return 0;
}