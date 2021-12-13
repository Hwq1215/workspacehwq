#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

int main(){
    system("pause");
}

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = 0;
        int max = 0;
        vector<int> rMax (n,0);
        vector<int> cMax (n,0);
        for(int i = 0;i<n;i++){
            max = 0;
            for(int j = 0;j<n;j++){
                max = grid[i][j]>max? grid[i][j]:max; 
            }
            rMax[i] = max;
        }
        for(int i = 0;i<n;i++){
            max = 0;
            for(int j = 0;j<n;j++){
                max = grid[j][i]>max? grid[j][i]:max; 
            }
            cMax[i] = max;
        }
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                total += (cMax[c]<rMax[r]?cMax[c]:rMax[r]) - grid[r][c];
            }
        }
        return total;
    }
};