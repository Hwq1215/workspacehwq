#include<bits/stdc++.h>

using namespace std;
int dirs[4][2] = {(0,1),(0,-1),(1,0),(-1,0)};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int hieght = isWater.size(),cols =isWater[0].size();  
        queue<pair<int,int>> q;
        vector<vector<int>> ans(hieght,vector<int> (cols,-1));
        for(int i = 0;i<hieght;i++){
            for (int j = 0;j<cols;j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.emplace(i,j);
                }
            }
        }
        int x,y;
        while(!q.empty()){
            auto &p = q.front();
            for(auto &dir: dirs){
                x = p.first + dir[0];
                y = p.second + dir[1];
                if(x>-1&&x<hieght && y>-1&&y<cols && ans[x][y] == -1){
                    ans[x][y] = ans[p.first][p.second]+1;
                    q.emplace(x,y); 
                }
            }   
            q.pop();
        } 
        return ans;
    }
};
int main(){
system("pause");
return 0;
}