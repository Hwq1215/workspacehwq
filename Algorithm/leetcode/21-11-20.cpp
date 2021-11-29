/*https://leetcode-cn.com/problems/longest-harmonious-subsequence/submissions/
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int begin = 0;
        int res = 0;
        int end = 0;
        for(;end<nums.size();end++){
            while(nums[end]-nums[begin]>1){
                begin++;
            }
            if(nums[begin]==nums[end]-1){
                res=res>(end-begin+1)?res:end-begin+1;
            }
        }
        return res;
    }
};