#include<bits/stdc++.h>
using namespace std;
#include"graph.hpp"
#include"Utils.hpp"
#include"FileInput.hpp"
void meum(){
    cout<<"-***请选择操作:"<<endl;
    cout<<"1.创建图"<<endl;
    cout<<"2.查询景点"<<endl;
    cout<<"3.旅游信息导航"<<endl;
    cout<<"4.搜索最短路径"<<endl;
    cout<<"5.铺设电路规划"<<endl;
    cout<<"6.?"<<endl;
    cout<<"7.退出"<<endl;
}
int main(){ 
    system("chcp 65001");

    vector<Place> places; 
    vector<Road>  roads; 
    Graph graph;
char c = '0';
while(c!='7'){
    meum();
    int org = -1;
    int target = -1;
    cin>>c;
    switch (c)
    {
    case '1':
        cout<<"正在创建.";
        places = File_places("D:\\VSCodeWorkSpace\\DateStructureExeprience\\Exeprience\\Exeprience2\\places.txt");
        cout<<".";
        roads  = File_roads("D:\\VSCodeWorkSpace\\DateStructureExeprience\\Exeprience\\Exeprience2\\roads.txt");
        cout<<"."<<endl;
        graph = Graph(places,roads);
        cout<<"创建完成"<<endl;
        break;
    case '2':
        graph.getPlaces();
        graph.getRoads();
        break;
    case '3':
        graph.getDfsRoads();
        break;
    case '4':
        cout<<"请输入起始和结尾的景点编号"<<endl;
        scanf("%d%d", &org,&target);
        graph.getDijkstra(org-1,target-1);
        break;
    case '5':
        graph.getPrim(0);
        break;
    default:  
        break;
    }
}
system("pause");
return 0;
}