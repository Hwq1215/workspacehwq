#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
using namespace std;

void sortstable( vector<pair<string,int>> &stu){
    pair<string,int> instead;
    int length = stu.size();
    for(int i = 0;i < length-1;i++){
        for(int j = length-1;j>0;j--){
            if(stu[j].second>stu[j-1].second){
                instead = stu[j-1];
                stu[j-1] = stu[j];
                stu[j] = instead;
            }
        }
    } 
}

void giveAnswer(vector<pair<string,int>> &stu){
    for(int i = 0;i<stu.size();i++){
        cout<<stu[i].first<<" "<<stu[i].second<<endl;
    }
} 
int main(){
    int n;
    int lastOne = 1000;
    bool error = false;
    cin>>n;
    vector<pair<string,int>> stu(n);
    vector<pair<string,int>> stuSort(n);
    for(int i = 0; i<n ;i++){
        cin>>stu[i].first;
        cin>>stu[i].second;
    }
    for(int i = 0; i<n ;i++){
        cin>>stuSort[i].first;
        cin>>stuSort[i].second;
        if(stuSort[i].second > lastOne){
            error = true;
        }
        lastOne = stuSort[i].second; 
    }
    sortstable(stu);
    if(error){
        cout<<"Error"<<endl;
        giveAnswer(stu);
    }
    else if(stu == stuSort){
        cout<<"Right"<<endl;
    }
    else{
        cout<<"Not Stable"<<endl;
        giveAnswer(stu);
    }
    return 0;
}