#include<bits/stdc++.h>
#include"FileInput.hpp"
using namespace std;

vector<Place> File_places(string pPlaces){
    vector<Place> places;
    FILE *p = fopen(pPlaces.c_str(),"r");
    if(!p){
        cout<<"打开文件失败"<<endl;
        return places;
    }
    int PlaceSize = 0;
    fscanf(p,"%d/n",&PlaceSize);
    places.resize(PlaceSize);
    for(int i = 0;i<PlaceSize;i++){
        char str1[50],str2[50];
        fscanf(p,"%s\n%s\n",str1,str2);
        string name(str1);
        string introduce(str2);
        places[i].name = name;
        places[i].introduce = introduce;
    }
    fclose(p);
    return places;
}

vector<Road> File_roads(string pRoads){
    vector<Road> roads;
    FILE *p2 = fopen(pRoads.c_str(),"r");
    if(!p2){
        cout<<"打开文件失败"<<endl;
        return roads;
    }

    int RoadsSize = 0;
    fscanf(p2,"%d/n",&RoadsSize);
    roads.resize(RoadsSize);
    for(int i = 0;i<RoadsSize;i++){
        char str1[50],str2[50];
        fscanf(p2,"%s\n%s\n%d\n",str1,str2,&roads[i].length);
        string place_A(str1);
        string place_B(str2);
        roads[i].first = place_A;
        roads[i].second = place_B;
    }
    fclose(p2);
    return roads;
}

