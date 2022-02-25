#include<bits/stdc++.h>
using namespace std;
int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
private:
    vector<vector<int>> grid;
    int res;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->grid = grid;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) res++;
                }
        }
        int i = 0,j = 0;;
        //上
        for(j = 0;j<grid[0].size();j++){
            if(grid[i][j]!=0){
                search(i,j);
            }
        }
        //左
        j = 0;
        for(i = 1;i<grid.size();i++){
            if(grid[i][j]){
                search(i,j);
            }
        }
        //右
        j = grid[0].size()-1;
        for(i = 1;i<grid.size();i++){
            if(grid[i][j]){
                search(i,j);
            }
        }
        //下
        i = grid.size()-1;
        for(j = 1;j<grid[0].size();j++){
            if(grid[i][j]){
                search(i,j);
            }
        }
        return res;
    }

    void search(int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0){
            return;
        }else{
            grid[i][j] = 0;
            res--;
            for(auto dir: dirs){
                int x = i+dir[0],y = j+dir[1];
                search(x,y);  
            }
        }
    }
};
int main(){

system("pause");
return 0;
}
