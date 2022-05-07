#include<bits/stdc++.h>
using namespace std;
int dirs[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
int main(){
    long long x1,x2,y1,y2;
    long long x_pos,y_pos;
    cin>>x1>>y1>>x2>>y2;
    for(auto dir:dirs){
        x_pos = x1 + dir[0], y_pos = y1 + dir[1];
        if(abs(pow(x_pos-x2,2)+pow(y_pos-y2,2) - 5) < 1e-9){
            cout<<"Yes";
            system("pause");
            return 0;
        }
    }
    cout<<"No";
system("pause");
return 0;
}