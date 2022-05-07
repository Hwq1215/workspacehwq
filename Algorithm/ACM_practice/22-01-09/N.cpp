#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    char a[n+1][n+1],b[n+1][n+1];
    int i = 1;
    int j = 1;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    //1;
    int flag = 0;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            if(a[i][j]!=b[j][n+1-i]){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(i == n+1){
        cout<<"1";
        system("pause");
        return 0;
    } 
    //2
    flag = 0;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            if(a[i][j]!=b[n+1-j][i]){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(i == n+1){
        cout<<"2";
        system("pause");
        return 0;
    } 
    //3
    flag = 0;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            if(a[i][j]!=b[n+1-i][n+1-j]){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(i == n+1){
        cout<<"3";
        system("pause");
        return 0;
    }
    //4
    flag = 0;
    for(i = 1;i<=n;i++){
        for(j = 1;j<=n;j++){
            if(a[i][j]!=b[i][j]){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    if(i == n+1){
        cout<<"4";
        system("pause");
        return 0;
    }
    //5
    cout<<"5";
    system("pause");
    return 0;
}
