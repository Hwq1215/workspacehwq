#include<iostream>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
bool compsmall(vector<int> &a,vector<int> &b){
    int i;
    for(i = 0;i<a.size()&&i<b.size();i++){
        if(a[i]<b[i]){
            return true;
        }
        else if(a[i]>b[i]){
            return false;
        }
    }
    if(a.size()<b.size()) return true;
    else return false;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int>> dat(n); 
    int cnt = 0;
    for(int i = 0;i<n;i++){
        string inp;
        cin>>inp;
        for(int j = 0;j<inp.size();j++){
            if(inp[j] == '.'){
                dat[i].push_back(cnt);
                cnt = 0;
            }else{
                cnt = cnt*10 + (inp[j]-'0');
            }
        }
        dat[i].push_back(cnt);
        cnt = 0;
    }
    for(int i = 0 ;i<dat.size()-1; i++){
        for(int j = dat.size()-1;j>i;j--){
            auto temp = dat[j-1]; 
            if(compsmall(dat[j],dat[j-1])){
                dat[j-1] = dat[j];
                dat[j] = temp;  
            }
        }
        for(int k = 0;k<dat[i].size();k++){
            cout<<dat[i][k];
            if(k != dat[i].size()-1) cout<<'.';
        }
        cout<<endl;
    }
    for(int k = 0;k<dat[n-1].size();k++){
        cout<<dat[n-1][k];
        if(k != dat[n-1].size()-1) cout<<'.';
        }
}