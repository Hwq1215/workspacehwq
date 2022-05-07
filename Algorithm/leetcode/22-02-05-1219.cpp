#include<bits/stdc++.h>
using namespace std;
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
    vector<vector<int>> grid;
    int res = 0;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        this->grid = grid;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
               if(grid[i][j]!=0) search(0,i,j);
            }
        }
        return res;
    }
    void search(int gold,int row,int col){
        if(row==-1||col==-1||row==grid.size()||col==grid[0].size()||grid[row][col]==0){ return;}
        int g = grid[row][col];
        gold += g;
        grid[row][col] = 0;
        res = max(res,gold);
        for(auto dir:dirs){
            int x = row + dir[0], y = col +dir[1];
            search(gold,x,y);
        }
        gold -= g;
        grid[row][col] = g;
    }
};
int main(){
    Solution s;
    vector<vector<int>> g = {{0,6,0},{5,8,7},{0,9,0}};
    cout<<s.getMaximumGold(g);
system("pause");
return 0;
}