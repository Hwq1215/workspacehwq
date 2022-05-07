#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int max = 0,cnt = 0,sum = 0;
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        if(i == 0){
            max = num;
            cnt = 1;
        }else if(num > max){
            max = num;
            cnt = 1;
        }else if(num == max){
            cnt++;
        }
        sum += num;
    }
    cout<<(sum - max*cnt);
system("pause");
return 0;
}