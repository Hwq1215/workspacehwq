#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,sum = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int cnt;
        sum = 0;
        scanf("%d",&cnt);
        for(int j = 0;j<cnt;j++){
            scanf("%d",&a);
            sum += a;
        }
        printf("%d\n", sum%cnt?1:0);    
    }
return 0;
}