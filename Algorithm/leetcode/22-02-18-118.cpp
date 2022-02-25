#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 1;i<=numRows;i++){
            vector<int> addRes(i,1);
            for(int j = 1;j<i-1;j++){
                addRes[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(addRes);
        }
        return res;
    }
};
int main(){
Solution s;
s.generate(5);
system("pause");
return 0;
}
