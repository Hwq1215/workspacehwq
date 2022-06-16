#include<bits/stdc++.h>
using namespace std;

int m[6][6];
vector<pair<int,int>> v;
vector<pair<int,int>> res;
void dsf(int x,int y);
int main(){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin>>m[i][j];
        }
    }
dsf(0,0);

for(int i = 0;i<res.size();i++){
    cout<<"("<<res[i].first<<","<<res[i].second<<")"<<endl;
}

system("pause");
return 0;
}

void dsf(int x,int y){
    v.push_back(make_pair(x,y));
    if(x == 4 && y == 4){
        res = v;
        return;
    }
    if(x == 4){
        if(m[x][y+1] == 0){
            dsf(x,y+1);
        }
        v.pop_back();
        return;
    }else if(y == 4){
        if(m[x+1][y] == 0){
            dsf(x+1,y);
        }
        v.pop_back();
        return;
    }else if( x<4 && y<4){
        if(m[x][y+1] == 0){
        dsf(x,y+1);
        }
        if(m[x+1][y] == 0){
        dsf(x+1,y);
        }
    }
    v.pop_back();
}