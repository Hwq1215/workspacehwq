#ifndef FC25F6BC_CF67_4D87_8E1F_66A41946067F
#define FC25F6BC_CF67_4D87_8E1F_66A41946067F
#include<bits/stdc++.h>
using namespace std;

class Utils{
    public:
    vector<vector<int>> dsf_ans;
    vector<vector<int>> init;
    vector<bool> visit;

    public:
    Utils(){};
    Utils(vector<vector<int>> & init){
        this->init = init;
        visit.resize(init.size(),false);
    }

    void dsf_init();

    void dsf(int index,vector<int> res);

    vector<vector<int>> dsf_all();
    
    vector<int> dijkstra(int org,int target,int & length);
    
    vector<pair<int,int>> prim(int org,int &length);
};

#endif /* FC25F6BC_CF67_4D87_8E1F_66A41946067F */
