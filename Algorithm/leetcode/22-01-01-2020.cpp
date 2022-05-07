#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int> > res(n);
        int col = -1;
        int j = 0;
        for(int i = 0;i<original.size();i++){
            if(i%m){
                j = 0;
                col++;
                res[col][j++] = original[i];
            }else{
                res[col][j++] = original[i];
            }                                                                          
        }
        return res;
    }
};

int main(){

system("pause");
return 0;
}

