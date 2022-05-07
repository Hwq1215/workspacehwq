#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> another(n,0);
        vector<int> cnt(n,0);
        for(int i = 0;i<trust.size();i++){
            cnt[trust[i][1]-1]++;
            another[trust[i][0]-1]++;
        }
        for(int i = 0;i<trust.size();i++){
            if(cnt[i] == n-1&& another[i]){
                return i+1;
            }
        }
        return -1;
    }
};