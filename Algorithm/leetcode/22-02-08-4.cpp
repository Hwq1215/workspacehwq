#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int mid,left,right;
        for(int i = 0;i<matrix.size();i++){
            left = 0,right = matrix[i].size()-1;
            mid = (left + right)/2;
            while(left<=right){
                if(matrix[i][mid]>target){
                    right = mid;
                }else if(matrix[i][mid]<target){
                    left = mid;
                }else{
                    return true;
                }
            }   
        }
        return false;   
    }
};
int main(){

system("pause");
return 0;
}