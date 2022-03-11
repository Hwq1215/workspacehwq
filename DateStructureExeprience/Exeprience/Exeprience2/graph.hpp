#include<bits/stdc++.h>
#include"Place.hpp"
#include"road.hpp"
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

    Graph(vector<Place> places,vector<Road> roads){
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
            if(t[order_A][order_B]<roads[i].length&&t[order_B][order_A]<roads[i].length){
                t[order_A][order_B] = roads[i].length;
                t[order_B][order_A] = roads[i].length;
            }
        }
        this->init = t;
    }

    void getRoads(){
        cout<<"景点名字    景点名字    景点距离"<<endl;
        for(int i = 0;i<roads.size();i++){
            printf("%-8s",roads[i].first);
            printf("%-8s",roads[i].second);
            printf("%d",roads[i].length);
            printf("/n");
        }
    }
    void getPlaces(){
        cout<<"景点名字        景点介绍"<<endl;
        for(int i = 0;i<places.size();i++){
            printf("%-12s",places[i].name);
            printf("%s",places[i].introduce);
            printf("/n");
        }
    }
    
};

