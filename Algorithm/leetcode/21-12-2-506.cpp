#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        int len = score.size();
        int cnt = 0;
        for(int i = 0;i<len;i++){
            for(int j = 0;j<len;j++){               
                if(score[j] > score[i]){
                    cnt++;
                }
            }
            if(cnt == 0){
                ans.push_back("Gold Medal");
            }
            else if(cnt == 1){
                ans.push_back("Silver Medal");
            }
            else if(cnt == 2){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(cnt+1));
            }
            cnt = 0;
        }
        return ans;
    }
};