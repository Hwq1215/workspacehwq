#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int beg = 0,end = 0;
        string res = ""; 
        for(beg = 0;beg<s.size();beg++){
            for(end = beg+1;end<=s.size();end++){
            if(end-beg > res.size()){
                string ins = s.substr(beg,end-beg);
                string cop = ins;
                reverse(cop.begin(),cop.end());
                if(ins.compare(cop) == 0){
                res = ins;
            }  
        }
        }
    }
    return res;
    }
};
int main(){
Solution s;
string res = s.longestPalindrome("cbbd");
cout<<res;
system("pause");
return 0;
}