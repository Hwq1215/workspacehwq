//https://leetcode-cn.com/problems/range-addition-ii/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina=m,minb=n;
        for(const auto &op:ops){
            mina=min(mina,op[0]);
            minb=min(minb,op[1]);
        }
        return mina*minb;
    }
};

int main(){
    Solution s;
    int m=3;
    int n=3;
    vector<vector<int>> op = {{2,2},{3,3}};
    int cnt = s.maxCount(m,n,op);
    cout<<cnt;
    system("pause");
}