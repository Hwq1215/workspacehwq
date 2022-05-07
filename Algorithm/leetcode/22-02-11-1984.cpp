#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool cmp(const int &front,const int &behind){
        return front>behind;
    }
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT32_MAX;
        sort(nums.begin(),nums.end(),cmp);
        for(int temp = 0;temp<nums.size()-k-1;temp++){
            res = min(res,(nums[temp] - nums[temp+k-1])); 
        }
        return res;
    }
};
int main(){

system("pause");
return 0;
}