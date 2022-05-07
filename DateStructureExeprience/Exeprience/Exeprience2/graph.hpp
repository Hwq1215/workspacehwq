#include<bits/stdc++.h>
#include"Place.hpp"
#include"Road.hpp"
#include"Utils.hpp"
using namespace std;

class Graph{
    private:
    vector<vector<int>> init;
    vector<vector<int>> result;
    vector<Place> places;
    vector<Road> roads;
    map<string,int> record;

    public:
    Graph(){};
    Graph(vector<vector<int>> inp){
        this->init = inp;
    } 

    Graph(vector<Place> & places,vector<Road> & roads){
        this->places = places;
        this->roads = roads;
        int placeSize = places.size();
        for(int i = 0;i<placeSize;i++){
            record[places[i].name] = i;
        }
        vector<vector<int>> t(placeSize,vector<int>(placeSize,INT32_MAX));
        for(int i = 0;i<placeSize;i++){ t[i][i] = 0; }
        for(int i = 0;i<roads.size();i++){
            int order_A = record[roads[i].first];
            int order_B = record[roads[i].second];
            if(t[order_A][order_B]>roads[i].length&&t[order_B][order_A]>roads[i].length){
                t[order_A][order_B] = roads[i].length;
                t[order_B][order_A] = roads[i].length;
            }
        }
        this->init = t;
    }

    void getRoads(){
        cout<<"——————景点路线——————"<<endl;
        cout<<"景点名字    景点名字    景点距离"<<endl;
        for(int i = 0;i<roads.size();i++){
            printf("%-13s",roads[i].first.c_str());
            printf("%-13s",roads[i].second.c_str());
            printf("%d",roads[i].length);
            printf("\n");
        }
    }

    void getPlaces(){
        cout<<"——————景点详情——————"<<endl;
        cout<<"景点编号        景点名字        景点介绍"<<endl;
        for(int i = 0;i<places.size();i++){
            printf("%-17d",i+1);
            printf("%-17s",places[i].name.c_str());
            printf("%s",places[i].introduce.c_str());
            printf("\n");
        }
    }
    
    void getDfsRoads(){
        Utils utils(init);
        vector<vector<int>> dsfRoads = utils.dsf_all();
        for(int i = 0;i<dsfRoads.size();i++){
            printf("第%d条路线: \n",i+1);
            for(int j = 0;j<dsfRoads[0].size();j++){
                printf("%s  ",places[dsfRoads[i][j]].name.c_str());
                if(j != dsfRoads[0].size()-1){
                    printf("-> ");
                }
            }
            printf("\n");
        }
    }

    void getDijkstra(string org_str,string target_str){
        int org = 0,target = 0;
        if(record.count(org_str) && record.count(target_str)){
            org = record[org_str];
            target = record[target_str];
        }else{
            printf("找不到指定的景点");
            return;
        }
        int total_length = 0;
        Utils utils(init);
        vector<int> res = utils.dijkstra(org,target,total_length);
        printf("最短路径是:\n");
        printf("总距离是:%d\n",total_length);
        for(int i = 0;i<res.size();i++){
            printf("%s",places[res[i]].name.c_str());
            if(i != res.size() - 1){
                printf(" -> ");
            }
        }
    }

    void getDijkstra(int org,int target){
        if(!(org!=target && org>-1 && org<init.size() && target>-1 && target<init.size())){
            printf("找不到指定的景点或输入错误");
            return;
        }
        int total_length = 0;
        Utils utils(init);
        vector<int> res = utils.dijkstra(org,target,total_length);
        printf("最短路径是:\n");
        printf("总距离是:%d\n",total_length);
        for(int i = 0;i<res.size();i++){
            printf("%s",places[res[i]].name.c_str());
            if(i != res.size() - 1){
                printf(" -> ");
            }
        }
        printf("\n");
    }

    void getPrim(int org){
        if(org<0 && org>=init.size()){
            cout<<"寻找线路错误"<<endl; 
            return;
        }
        int length = 0;
        Utils utils(init);
        vector<pair<int,int>> res= utils.prim(org,length);
        printf("铺设电缆的道路:\n");
        cout<<"铺设的电网的总距离:"<<length<<endl;
        cout<<"景点名字    景点名字    景点距离"<<endl;
        for(int i = 0;i<res.size();i++){
            printf("%-13s",places[res[i].first].name.c_str());
            printf("%-13s",places[res[i].second].name.c_str());
            printf("%d",init[res[i].first][res[i].second]);
            printf("\n");
        }
    }
};

