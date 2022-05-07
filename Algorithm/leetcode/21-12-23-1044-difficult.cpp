#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestDupSubstring(string s) {
        string res = "";
        int i = 0,j = 0;
        for(i = 0;i<s.size()-1;i++){
            string str1 = s.substr(i+1,s.size());
            string str2 = s.substr(i,s.size()-1);
            while(str2.size() != 0){
                if(res.size()<str2.size() && str1.find(str2) != str1.npos){
                    res = str2;
                }
                str2.pop_back();
            }
        }
        return res;
    }
};

int main(){
     Solution s;
    s.longestDupSubstring("banana");
    system("pause");
}
//not pass time limited
