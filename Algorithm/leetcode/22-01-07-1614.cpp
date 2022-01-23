#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int max = 0;
        int cnt = 0;
        int i = 0;
        while(i<s.size()){
            if(s[i] == '('){
                st.push(s[i]);
                cnt = st.size();
                max = max < cnt? cnt:max;
            }else if(s[i] == ')'){
                if(!st.empty()) st.pop();
            }
            i++;
        }
        return max;
    }
};

int main(){

system("pause");
return 0;
}