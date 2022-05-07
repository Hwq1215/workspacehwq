#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        bool flag1 = false,flag2 =false;
        int begin = 0;
        int end = 0;
        for(end = 0;end<text.size();end++){
            if(text[end] == ' '){
                string str;
                str.append(text,begin,end - begin);
                if(flag1&&flag2){
                    res.push_back(str);
                    flag2 = false;
                    flag1 = (str == first)? true:false;
                }
                if(str == second&&flag1){
                    flag2 = true;
                }else if(str == first){
                    flag1 = true;
                }else{
                    flag1 = flag2 = false;
                }
                begin = end + 1;
            }
        }
        string str;
                str.append(text,begin,end - begin);
                if(flag1&&flag2){
                    res.push_back(str);
                    flag2 = false;
                    flag1 = (str == first)? true:false;
                }
                if(str == second&&flag1){
                    flag2 = true;
                }else if(str == first){
                    flag1 = true;
                }else{
                    flag1 = flag2 = false;
                }
                begin = end + 1;
        return res;
    }
};

int main(){
    Solution s;
    vector<string> res;
    res = s.findOcurrences("alice is a good girl she is a good student"
                    ,"a"
                    ,"good");
    system("pause");
}