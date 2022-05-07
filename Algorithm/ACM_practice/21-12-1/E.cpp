#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    bool flag = false;
    int mid,l,r,A,B;
    for(int i = 1;i<sqrt(2*n);i++){
        A = i*(i+1)/2;
        l = i,r = sqrt(2*n);
        mid = (l + r)/2;
        B = (mid*mid+mid)/2;
        while(l<=r){
            if(A + B > n){
                r = mid-1;
                mid = (r+l)/2;
            }
            else if(A + B < n){
                l = mid+1;
                mid = (l+r)/2;
            }
            else{
                flag = true;
                break;
            }
            B = (mid*mid+mid)/2;
        }
        if(flag) break;
    }    
    if(flag)
    cout<<"YES";
    else 
    cout<<"NO";
    return 0;
}