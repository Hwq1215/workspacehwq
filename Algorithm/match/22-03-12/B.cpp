#include<bits/stdc++.h>
using namespace std;
int a[1006];
int b[1006];
int main(){
map<int,int> m;
int n = 0;
int res_1 = 0;
int res_2 = 0;
scanf("%d",&n);
for(int i = 0;i<n;i++){
    int num;
    scanf("%d",&num);
    a[i] = num;
    m[num]++;
}
for(int i = 0;i<n;i++){
    int num;
    scanf("%d",&num);
    if(num == a[i]){
        res_1++;
        m[num]--;
    }else{
        m[num]++;
    }
}
for(auto num :m){
    if(num.second>1){
        res_2++;
    }
}
cout<<res_1<<endl<<res_2;
system("pause");
return 0;
}