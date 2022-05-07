#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    int rows,cols;
    vector<vector<int> > a;
public:  
    Solution(int m, int n) {
        rows = m;
        cols = n;
        a.resize(m);
        for(int i = 0;i<a.size();i++){
            a[i].resize(n);
            for(int j = 0;j<a[i].size();j++){
                a[i][j] = 0;
            }
        }
        }
    
    vector<int> flip() {
        int total = rows*cols;
        int num = rand()%total;
            vector<int> res(2,0);
            res[0] = num/cols;
            res[1] = num/rows;
        if(a[res[0]][res[1]]==1) {
            return flip();
        }
        else{
            return res; 
        }
        return  res;
    }
    
    void reset() {
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                a[i][j] = 0;
            }
        }
    }
};

int main(){
    Solution s(3,3);
    s.flip();
    s.flip();
    system("pause");
}