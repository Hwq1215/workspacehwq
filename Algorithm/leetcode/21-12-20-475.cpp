#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
}
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int r = 0;
        int j = 0;
        for(auto house:houses){
                 while(j != (heaters.size()-1) && abs(heaters[j]-house) > abs(heaters[j+1]-house)) j++;
                    r = max(abs(heaters[j] - house),r); 
                }          
        return r;
    }
};