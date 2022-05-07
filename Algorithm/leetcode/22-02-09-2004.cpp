#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int > mymap;
        for(int num:nums){
            res += (mymap.count(num-k))? mymap[num-k]:0;
            res += (mymap.count(num+k))? mymap[num+k]:0;
        }   
        return res;
    }
};
int main(){

system("pause");
return 0;
}