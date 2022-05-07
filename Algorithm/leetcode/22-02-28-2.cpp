#include<bits/stdc++.h>
using namespace std;
class Solution {
    int res = 0,n;
    int zero;
    vector<int> dep;
    vector<vector<int>> requests;
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        this->requests = requests;
        vector<int> dep(n,0);
        this->dep = dep;
        this->n = n;
        zero = n;
        dsf_s(0,0);
        return res;
    }
    void dsf_s(int effect,int pos){
        if(pos>requests.size()-1){
            if(effect>res && zero == n) res = effect;
            return;
        }
        if(effect>res && zero == n) res =  effect;
        int zero_init = zero;
        if(requests[pos][0] == requests[pos][1]){
            dsf_s(effect+1,pos+1);
        }else{
            if(dep[requests[pos][0]] == 0){
            zero--;
            }
            if(dep[requests[pos][1]] == 0){
            zero--;
            }
            dep[requests[pos][0]]--;
            dep[requests[pos][1]]++;
            if(dep[requests[pos][0]] == 0){
            zero++;
            }
            if(dep[requests[pos][1]] == 0){
            zero++;
            }
            dsf_s(effect+1,pos+1);
            zero = zero_init;
            dep[requests[pos][0]]++;
            dep[requests[pos][1]]--;
            dsf_s(effect,pos+1);
        }
        
    }
};
int main(){
    vector<vector<int>> a{{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};
    Solution s;
    cout<<s.maximumRequests(3,a);
system("pause");
return 0;
}