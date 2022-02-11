#include<bits/stdc++.h>
using namespace std;

int main(){
int cols,rows;
cin>>rows>>cols;
int rec[rows][cols];
for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
        cin>>rec[i][j];
    }
}
for(int i = 0;i<cols;i++){
    for(int j = 0;j<rows;j++){
        cout<<rec[j][i];
        if(j!=rows-1) cout<<" ";
    }
    cout<<endl;
}
system("pause");
return 0;
}