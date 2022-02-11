#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
    if(s.compare("") != 0)result.push_back(s);
    i = pos + pattern.size() - 1;
    }
}
return result;
}
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string > res;
        string inp = s1 + " " + s2;
        res = split(inp," ");
        for(int i = 0;i<res.size();i++){
            bool change = false;
            for(int j = i+1;j<res.size();j++){
                if(res[i].compare(res[j])==0){
                    res.erase(res.begin()+j);
                    j--;
                    change = true;
                }
            }
            if(change){
                res.erase(res.begin()+i);
                    i--; 
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    string str_1 = "this is a apple",str_2="this is no a apple";
    vector<string> res = s.uncommonFromSentences(str_1,str_2);
    for(auto &m : res){
        cout<<m<<endl;
    } 
system("pause");
return 0;
}