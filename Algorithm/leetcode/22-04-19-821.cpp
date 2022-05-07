#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> c_pos;
        vector<int> ans;
    
        // get the c pos , put them into the arr;
        for(int i = 0;i<s.size();i++){
            if(s[i] == c){
                c_pos.push_back(i);
            }
        }

        // calculate the pos to the char c;
        int ptr = 0;        //前指针位置
        int front_ptr = c_pos[0];
        int last_ptr = INT32_MAX; 
        if(c_pos.size()>1){
            last_ptr = c_pos[1];
        }
        for(int i = 0;i<s.size();i++){
            if(i==front_ptr){
                ans.push_back(0);
                if(ptr+1 < c_pos.size()){
                    ptr ++;
                    front_ptr = last_ptr;
                    last_ptr = c_pos[ptr];
                }
            }else{
                ans.push_back((abs(i-front_ptr),abs(i-last_ptr)));
            }
        } 
        return ans;
    }
};

// search the c pos in the string;



int main(){
Solution s;
vector<int> arrays= s.shortestToChar("fsd",1);
for(int i = 0;i<arrays.size();i++) cout<<arrays[i]<<" ";
system("pause");
return 0;
}

