#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int beg = 0, end = 0;
        int res = 0;
        map<char,int> count;
        while(end<s.size()){
            count[s[end]]++;
            if(count[s[end]] > 1){
                res = max(res,end-beg);
                while(count[s[end]] != 1){
                    count[s[beg]]--;
                    beg++;
                }
            }
            end++;
        }
        res = max(res,end-beg-1);
        return res;   
    }
};
int main(){

system("pause");
return 0;
}