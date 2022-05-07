#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){

}
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt = 0;
        int min = 1002;
        string res;
        vector<int> num(26,0);
        for(int i = 0;i<licensePlate.size();i++){
            if(licensePlate[i]>='A'&&licensePlate[i]<='Z'){
                num[licensePlate[i] -'A']++;
                cnt++;
            }
            else if(licensePlate[i]>='a'&&licensePlate[i]<='z'){
                num[licensePlate[i]-'a']++;
                cnt++;
            }
        }
        for(int i = 0;i<words.size();i++){
                if(words[i].size()<cnt){
                }else{
                    if(words[i].size()<min&&comString(words[i],num)){
                       res = words[i];
                       min = words[i].size();
                    }
                }
            }
            return res;
        }

    
    bool comString(string str,vector<int> num){
        int val = 0;
        vector<int> str_num(26,0);
        for(int i = 0;i<str.size();i++){
            str_num[ str[i]-'a']++;
        }
        for(int i = 0;i<26;i++){
            val = num[i] - str_num[i];
            if(val>0){
                return false;
            } 
        }
        return true;
    }
};