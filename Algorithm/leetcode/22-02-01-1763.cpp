#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        string res;
        res.resize(1);
        vector<bool> prefect(150,true);
        map<char,int> letter;
        map<char,int> cop;        
        int end = 0,beg = 0;
        for(beg = 0;beg<s.size();beg++){
            letter[s[beg]]++;
        }
        for(int j = 0;j<26;j++){
            if((!letter['a'+j]&&letter['A'+j]) || (letter['a'+j]&&!letter['A'+j])){
                prefect['a'+j] = false;
                prefect['A'+j] = false;
            }
        }
        letter.clear();
        beg = 0;
        int i = 0;
        //滑动窗口，分割字符串。
        for(end = 0;end<=s.size();end++){
            if(end==s.size()||prefect[s[end]] == false){
                while(end - beg>res.size()){
                    letter[s[beg]]--;
                    beg++;
                    cop = letter;
                    for(int j = end;j>beg;j--){
                        for(i = 0;i<26;i++){
                            if(!((cop['a'+i]>0&&cop['A'+i]>0) || (cop['a'+i] == 0&&cop['A'+i]==0))){
                            break;
                            }
                        }
                    if(i == 26){
                        res = j-beg>res.size()? s.substr(beg,j-beg):res;
                    }
                    cop[s[j-1]]--; 
                    }
                }
                beg = end+1;
                letter.clear();
            }else{
                letter[s[end]]++;
                for(i = 0;i<26;i++){
                    if(!((letter['a'+i]>0&&letter['A'+i]>0) || (letter['a'+i] == 0&&letter['A'+i]==0))){
                        break;
                    }
                }
                if(i == 26){
                    res = end-beg+1>res.size()? s.substr(beg,end - beg + 1):res;
                }
            }
        }
        if(res.size() == 1) return "";
        return res;
    }
};
int main(){
Solution s;
cout<<s.longestNiceSubstring("hyuHiIhu");
system("pause");
return 0;
}