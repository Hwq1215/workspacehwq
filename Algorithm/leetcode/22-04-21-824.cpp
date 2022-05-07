#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_fuYIn(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        return false;
    } 

    std::vector<std::string> split(std::string str, std::string pattern)
        {
        std::string::size_type pos;
        std::vector<std::string> result;
        str += pattern;
        int size = str.size();
        for (int i = 0; i < size; i++)
        {
        pos = str.find(pattern, i);
        if (pos < size)
        {
        std::string s = str.substr(i, pos - i);
        result.push_back(s);
        i = pos + pattern.size() - 1;
        }
    }
    return result;

    }
    string toGoatLatin(string sentence) {
        string ans = "";
        string addStr = "a";    
        vector<string> vec_str = split(sentence," ");
        for(int i = 0;i<vec_str.size();i++){
            if(is_fuYIn(vec_str[i][0])){
                ans.append(vec_str[i]);
            }else{
                string ins;
                ins.append(vec_str[i],1,vec_str[i].size()-1);
                char firstChar = vec_str[i][0];
                ins.push_back(firstChar);
                ans.append(ins);
            }
            ans.append("m");
            ans.append(addStr);
            addStr.append("a");
            if(i!=vec_str.size()-1){
                ans.append(" ");
            }
        }
    }
    
};
int main(){

system("pause");
return 0;
}
