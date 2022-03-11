#include<vector>
#include<iostream>
#include<map>
#include<string>

using namespace std;

vector<int> dfs(vector<vector<int>> init,int index){
    vector<int> res;
    res.push_back(index);
    while(res.size()!=init.size()){
        for(int i = 0;i<init[0].size();i++){
            if(index != i && init[index][i] != INT32_MAX){
                res.push_back(i);
            }
        }
    }
}