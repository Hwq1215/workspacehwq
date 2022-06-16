#include<bits/stdc++.h>
using namespace std;
vector<int> nums;
int main(){
    int res = 0;
int n,cnt;
cin>>n>>cnt;
for(int i = 0;i<n;i++){
    int temp;
    cin>>temp;
    nums.push_back(temp);
}
sort(nums.begin(),nums.end());
int affect = INT32_MIN;
for(int i = 0;i<nums.size();i++){
    if(affect < nums[i]){
        res ++;
        affect = nums[i] + cnt;
    }
}
cout<<res<<endl;
system("pause");
return 0;
}
