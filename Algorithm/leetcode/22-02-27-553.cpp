#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res;
        res.append(to_string(nums[0]));
        if(nums.size()==2){
            res.append("/");
            res.append(to_string(nums[1]));
        }else{
            res.append("/(");
            res.append(to_string(nums[1]));
            for(int i = 2;i<nums.size();i++){
                res.push_back('/');
                res.append(to_string(nums[i]));
            }
            res.push_back(')');
        }
        return res;
    }
};
