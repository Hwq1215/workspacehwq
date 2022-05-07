#include<bits/stdc++.h>
using namespace std;

class Utils{
    private:
    vector<int> dp;
    vector<vector<int>> input;
    int n;
    public:
    Utils(vector<vector<int>> input,int n ){
        this->input = input;
        this->n = n;
        this->dp = vector<int>(n,0);
        for(int i = 0;i<input[n-1].size();i++){
            dp[i] =  input[n-1][i];
        }
    }
public:
    int mathTotal(int i,int j){
    
    }
    int MaxSum(int i, int j)
    {
        if(i==n-1) return input[i][j];
        int x = MaxSum(i+1,j);
        int y = MaxSum(i+1,j+1);
        return max(x,y)+input[i][j];
    }

};


int main(){
    vector<vector<int>> in(5,vector<int>(5,0));
int i,j,n;
cin >> n;
for(i=0;i<n;i++)
for(j=0;j<=i;j++)
cin >> in[i][j];

Utils utils(in,n);
cout << utils.MaxSum(0,0) << endl;

 
system("pause");
return 0;
}