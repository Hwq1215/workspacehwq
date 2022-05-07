#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sDir(26),pDir(26);
        vector<int> ans;
        int start = 0,i = 0,n1 = s.size(),n2 = p.size();
        if(n1<n2) return ans;
        for(;i<n2;i++){
            sDir[s[i] - 'a'] ++;
            pDir[p[i] - 'p'] ++;
        }
        for(;i<n1;i++){
            if(sDir == pDir) ans.push_back(start);
            sDir[s[start++] - 'a'] --;
            sDir[s[i] - 'a'] ++;
        }
        return ans;
    }
    
};