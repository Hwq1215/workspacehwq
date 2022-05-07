#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){

}

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) { 
        map<int,int> largeOne;
        for(int i = 0;i<richer.size();i++){
            largeOne[i] = 501;
        }
        for(int i = 0;i<richer.size();i++){
            for(int j = 0;j<2;j++){
                largeOne[richer[i][1]] = largeOne[richer[i][0]] - 1;
            }
        }
    }
};