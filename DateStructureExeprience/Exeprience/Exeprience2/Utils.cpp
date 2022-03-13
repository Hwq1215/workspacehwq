#include"Utils.hpp"
#include"Road.hpp"
using namespace std;
//dsf 初始化
void Utils::dsf_init(){
    for(int i = 0;i<Utils::visit.size();i++){
        visit[i] = false;
    }
}

//一个起始点的dsf
void Utils::dsf(int index,vector<int> res){
    res.push_back(index);
    visit[index] = true;
    if(res.size()==Utils::init.size()){
        Utils::dsf_ans.push_back(res);
        return;
    }
    for(int i = 0;i<Utils::init.size();i++){
        if( i!=index && visit[i]==false && Utils::init[index][i] != INT32_MAX){
            dsf(i,res);
            visit[i] = false;
        } 
    } 
    return;
}

//全部路线dsf
vector<vector<int>> Utils::dsf_all(){
    for(int i = 0;i<Utils::init.size();i++){
        vector<int> res;
        Utils::dsf_init();
        Utils::dsf(i,res);
    }
    return Utils::dsf_ans;
}

//寻找两点的最短路径
vector<int> Utils::dijkstra(int org,int target,int & length){
    length = 0;
    vector<bool> visit(Utils::init.size(),false);
    visit[org] = true;
    vector<int> path(Utils::init.size(),org);                           //记录最短路径  path[i] = 离他最近的上一个点
    vector<int> res;
    int index = org;
    vector<int> farfrom(Utils::init[index]);    //整体到个体的距离
    int minNum = INT32_MAX;
    for(int s = 0;s<farfrom.size()-1;s++){
        minNum = INT32_MAX;
        index = -1;
        //挑出最短距离的编号
        for(int i = 0;i<farfrom.size();i++){
            if(visit[i] != true && farfrom[i]<minNum){ //找连通并且不是已经加入的最小点
                minNum = farfrom[i];
                index = i;
            }
        }
        //更新路径信息
        if(index>-1){
            visit[index] = true;
            for(int i = 0;i<farfrom.size();i++){
                if(visit[i] == false && Utils::init[index][i] != INT32_MAX && farfrom[index] != INT32_MAX && farfrom[index] + Utils::init[index][i] < farfrom[i]){
                    farfrom[i] = farfrom[index] + Utils::init[index][i];    //记录该点的最短路程
                    path[i] = index;                                        //记录该点最近的路径
                } 
            }
        }
    }
    //用栈把路线还原
    stack<int> stk;
    stk.push(target);
    int num = target;
    while(num != org){
        stk.push(path[num]);
        num = path[num];
    }
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
    length = farfrom[target];
    return res;
}

vector<pair<int,int>> Utils::prim(int org,int &length){
    vector<pair<int,int>> res;
    length = 0;
    vector<int> visit(Utils::init.size(),0);
    vector<int> farfrom(Utils::init[org]);
    vector<int> path(Utils::init.size(),org);
    int index_i = org;
    int index_j = org + 1;
    int minNum = INT32_MAX;
    visit[org] = 1;
    while(res.size() != farfrom.size()-1){
        index_i = -1;
        index_j = -1;
        minNum = INT32_MAX;
        for(int i = 0;i<visit.size();i++){ 
            if(visit[i] == 1){         //i:已经访问的点
                for(int j = 0;j<visit.size();j++){
                    if( !visit[j] && Utils::init[i][j] < minNum){       //index_j:未访问的点并且最小路径可达到
                        index_i = i;                            
                        index_j = j;
                        minNum = Utils::init[i][j];
                    }
                }
            }
        }
        if(index_j > -1 && index_i > -1){
            length += minNum;
            res.push_back(pair<int,int>(index_i,index_j));
            visit[index_j] = 1;
        }
    }
    return res;
}