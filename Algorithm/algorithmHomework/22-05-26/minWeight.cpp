#include<bits/stdc++.h>
using namespace std;
const int len = 105;

int weg[len][len];
int val[len][len];
vector<int> choose; 
vector<int> resChoose;
int n,m,allow;
int minWeight = INT32_MAX;

void dsf(int pos,int value,int weight);
int main(){
cin>>n>>m>>allow;

for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        cin>>weg[i][j];
    }
}

for(int i = 1;i<=n;i++){
    for(int j = 1;j<=m;j++){
        cin>>val[i][j];
    }
}
dsf(1,0,0);
for(int i = 0;i<resChoose.size();i++){
    printf("%d",resChoose[i]);
    if(i!=resChoose.size()-1) printf(" ");
}
printf("\n");
printf("%d",minWeight);
system("pause");
return 0;
}

void dsf(int pos,int value,int weight){
    if(value > allow){
        return;
    }else if(pos == n+1 && weight < minWeight){
        resChoose = choose;
        minWeight = weight;
        return;
    }else if(pos == n+1){
        return;
    }

    for(int i = 1;i<=m;i++){
        choose.push_back(i);
        dsf(pos+1,value + val[pos][i],weight + weg[pos][i]);
        choose.pop_back();
    }
}