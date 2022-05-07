#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        int left = 0,right = 0;
        string str = "";
        gen(str,n,n);
        return res;
    }
    void gen(string str,int left,int right){
        if(left>right){
            return; 
        }else if(left==0&&right==0){
            res.push_back(str);
        }else{
            if(left>0){
                gen(str.append("("),left-1,right);
            }
            gen(str.append(")"),left,right-1);
        }
    }
};
int main(){

system("pause");
return 0;
}