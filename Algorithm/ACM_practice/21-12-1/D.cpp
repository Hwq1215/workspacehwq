#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
ll divideChoose(ll left,ll right,ll tag);
ll DivideChoose(ll left,ll right,ll tag);
int main(){
    int n;
    cin>>n;
    ll k,x;
    for(int i = 0;i<n;i++){
        cin>>k;
        cin>>x;
        ll m = k*k;
        if(k > x){
            cout<<divideChoose(1,x,x)<<endl;
        }else if((1+k)*k/2 >= x){
            cout<<divideChoose(1,k,x)<<endl;
        }else if(k*k >= x){
            cout<< k + DivideChoose(1,k-1,x-((1+k)*k/2))<<endl;
        }else{
            cout<<2*k-1<<endl;
        }
    }
    return 0;
}

ll divideChoose(ll left,ll right,ll tag){
    ll result = right;
    ll mid = (left + right)/2;
    while(left < right){
        if((mid+1)*mid/2 > tag){
            right = mid -1;
            mid = (left + right)/2;
        }
        else if((mid+1)*mid/2 < tag){
            left = mid + 1;
            mid = (left +right)/2;
        }
        else{
            result = mid;
            break;
        }
        result = mid;
    }
    return result;
}
ll DivideChoose(ll left,ll right,ll tag){
    ll k = right;
    ll result = right;
    ll mid = (left + right)/2;
    while(left <= right){
        if((mid+k)*(k-mid+1)/2 < tag){
            right = mid -1;
            mid = (left + right)/2;
        }
        else if((mid+k)*(k-mid+1)/2 > tag){
            left = mid + 1;
            mid = (left +right)/2;
        }
        else{
            result = k - mid + 1;
            break;
        }
        result = k - mid + 1;
    }
    return result;
}