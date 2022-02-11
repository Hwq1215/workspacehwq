#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string res;
        int add = 0;
        int num_a,num_b;
        int i = 0,j = 0;
        while(i != a.size()||j != b.size()){
            if(i != a.size() && j!=b.size()){
                num_a = (a[i]-'0'), num_b = (b[j]-'0');
                res.push_back('0' + (num_a^num_b^add));//异或运算
                add = (num_a&&num_b) || (num_a&&add) || (num_b&&add); //与运算
                i++;
                j++;
            }else if(i!= a.size()){
                for(int k = i;i<a.size();i++){
                    num_a = a[i] - '0';
                    res.push_back('0'+num_a^add);
                    add = num_a&&add; 
                }
            }else{
                for(int k = j;j<b.size();j++){
                    num_b = b[j] - '0';
                    res.push_back('0'+num_b^add); 
                    add = num_b&&add;
                }
            }
        } 
        if(add) res.push_back('0'+add);
        reverse(res.begin(),res.end());
        return res;
    }
};
int main(){
Solution s;
s.addBinary("11","10");
system("pause");
return 0;
}