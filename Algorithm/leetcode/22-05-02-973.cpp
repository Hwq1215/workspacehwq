#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let,dig,ans;
        for(string str: logs){
            string content = str.substr(str.find(' ')+1,str.size()-str.find(' ')-1);
            int type = 0;
            if(content[0]>='0'&&content[0]<='9'){
                dig.push_back(str);
            }else{
                if(let.size() == 0) let.push_back(str);
                else{
                    int i = 0;
                    for(i = 0;i<let.size();i++){
                        if(content.compare(let[i].substr(let[i].find(' ')+1,let[i].size()-let[i].find(' ')-1))<0){
                            let.insert(let.begin()+i,str);
                            break;
                        }
                    }
                    if(i == let.size()) let.push_back(str);
                }
            }
        } 
        let.insert(let.end(),dig.begin(),dig.end());
        return let;
    }
};

int main(){
    vector<string> v={"j je", "b fjt", "7 zbr", "m le", "o 33"};
    Solution s;
    s.reorderLogFiles(v);
system("pause");
return 0;
}