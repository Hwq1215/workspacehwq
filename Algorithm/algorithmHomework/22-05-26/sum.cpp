#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
int flag = 0;
int tag;

void dsf(int sum);
int main(){
int n,sum;
cin>>n>>tag;

for(int i = 0;i<n;i++){
    int temp;
    cin>>temp;
    nums.push_back(temp);
    sum += temp;
}

if(sum < tag){
    cout<<"NO"<<endl;
    return 0;
}
dsf(0);
if(flag){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}
system("pause");
return 0;
}

void dsf(int sum){
    if(sum == tag){
        flag = true;
        return;
    }
    if(nums.size() == 0){
        return;
    }
    for(int i = 0;i<nums.size();i++){
        int pos = i;
        int temp = nums[i];
        nums.erase(nums.begin()+i);
        dsf(sum + temp);
        nums.insert(nums.begin()+pos,temp);
    }
}