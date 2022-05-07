#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> str_stack;
        int i = 0;
        while(i<n){
            string str = "";
            while(i<n && path[i]!='/'){
                str += path[i];
                ++i;
            }
            if(str != ""){
                if(str == ".."){
                    if(str_stack.size() != 0){
                        str_stack.pop();
                    }
                }else if(str != "."){
                    str_stack.push(str);
                }
            }
        }
        int len = str_stack.size();
        vector<string> str_instead(len);
        for(int k = 0;k<len;k++){
            str_instead[k] = str_stack.top();
            str_stack.pop();
        }
        string ans = "/";
        for(int k = len-1;k>0;k--){
            ans += str_instead[k];
            ans += "/";
        }
        if(len) ans += str_instead[0];
        return ans;
    }
};
int main(){

system("pause");
return 0;
}