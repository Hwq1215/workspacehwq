#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        unordered_map<int,int> rowMin;
        int minVal,maxVal,pos;
        for(int i = 0;i<matrix.size();i++){
            minVal = matrix[i][0];
            pos = 0;
            for(int j = 1;j<matrix[0].size();j++){
                if(minVal>matrix[i][j]){
                    minVal = matrix[i][j];
                    pos = j;
                }
            }
            if(!rowMin.count(pos)||rowMin[pos]<minVal) rowMin[pos] = minVal;
        }
        for(int i = 0 ;i<matrix[0].size();i++){
            if(rowMin.count(i)){
                int j = 0; 
                for(j = 0;j<matrix.size();j++){
                    if(matrix[j][i]>rowMin[i]) break;
                }
                if(j==matrix.size()) ans.push_back(rowMin[i]);
            }
        }
        return ans;
    }
};
int main(){
vector<vector<int>> input = {{3,7,8},{9,11,13},{15,16,17}};
Solution s;
vector<int> m = s.luckyNumbers(input);
for(int i = 0;i<m.size();i++){
    cout<<m[i]<<" ";
}
system("pause");
return 0;
}