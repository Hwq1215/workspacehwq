#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a,int b){
    return a>b;
}
int main(){
    vector<int> ji,ou;
    for(int i = 0;i<10;i++){
        int input;
        cin>>input;
        if(input%2){
            ji.push_back(input);
        }else{
            ou.push_back(input);
        }
    }
    sort(ji.begin(),ji.end(),compare);
    sort(ou.begin(),ou.end());
    for(int i = 0;i<ji.size();i++){
        cout<<ji[i]<<" ";
    }
    for(int i = 0;i<ou.size();i++){
        cout<<ou[i]<<" ";
    }
system("pause");
return 0;
}
