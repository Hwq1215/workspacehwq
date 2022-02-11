#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int res = 0;
        map<int,int> n;
        for(auto num:nums){
            if(n[num]==1){
                res -= num;
            }else if(n[num]==0){
                res += num;
            }
            n[num]++;
        }
        return res;
    }
};
int main(){
Solution s;
system("pause");
return 0;
}