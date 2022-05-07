#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int rows,cols;
    cin>>rows>>cols;
    int a[rows+1][cols+1];
    for(int i = 1;i<=rows;i++){
        for(int j = 1;j<=cols;j++){
            cin>>a[i][j];
        }
    }
    int n;
    cin>>n;
    for(int k = 0;k<n;k++){
        int rowFront, rowEnd, colFront, colEnd,sum = 0;
        cin>>rowFront>>rowEnd>>colFront>>colEnd;
        for(int i = rowFront;i<=rowEnd;i++){
            for(int j = colFront;j<=colEnd;j++){
                sum += a[i][j];
            }
        }
        cout<<sum<<endl;
    }

system("pause");
return 0;
}