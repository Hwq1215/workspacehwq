#include<bits/stdc++.h>
#include<map>
using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0;
        map<int,int> val;
        for(int i = 0;i<properties.size();i++){
            if(properties[i][1]>val[properties[i][0]]){
                for(int j = properties[i][0];properties[i][1]>val[j]&&j>0;j--){
                    val[j] = properties[i][1];
                }
            }
        }
        for(int i = 0;i<properties.size();i++){
            if(val[properties[i][0]+1]>properties[i][1]) res++;
        }
        return res;
    }
};

int main(){

system("pause");
return 0;
}