#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int arr[(int)1e6];
int main(){
int n,skip;
scanf("%d%d",&n,&skip);
vector<int> minArr,maxArr;
pair<int,int> maxVal(0,0);
pair<int,int> minVal(0,0);
int i = 0;
for(i = 0;i<skip;i++){
    scanf("%d",&arr[i]);
    if(i==0){
        maxVal.second = arr[i];
        minVal.second = arr[i];
    } 
    if(maxVal.second<arr[i]){
        maxVal.first = i;
        maxVal.second = arr[i];
    }
    if(minVal.second>arr[i]){
        minVal.first = i;
        minVal.second = arr[i];
    } 
}
maxArr.push_back(maxVal.second);
minArr.push_back(minVal.second);
while(i<n){
    scanf("%d",&arr[i]);
    if(maxVal.second<arr[i]){
        maxVal.first = i;
        maxVal.second = arr[i];
    }else if(i-skip==maxVal.first){
        maxVal.first = i-skip+1;
        maxVal.second = arr[i-skip+1];
        for(register int j = i-skip+2;j<=i;j++){
            if(arr[j]>maxVal.second){
                maxVal.first = j;
                maxVal.second = arr[j];
            }
        } 
    }
    if(minVal.second>arr[i]){
        minVal.first = i;
        minVal.second = arr[i];
    }else if(i-skip==minVal.first){
        minVal.first = i-skip+1;
        minVal.second = arr[i-skip+1];
        for(register int j = i-skip+2;j<=i;j++){
            if(arr[j]<minVal.second){
                minVal.first = j;
                minVal.second = arr[j];
            }
        } 
    }
    maxArr.push_back(maxVal.second);
    minArr.push_back(minVal.second);
    i++;
}
    for(register int pos = 0;pos<minArr.size();pos++){
        cout<<minArr[pos]<<" ";
    }
    cout<<endl;
    for(register int pos = 0;pos<maxArr.size();pos++){
        cout<<maxArr[pos]<<" ";
    }
    cout<<endl;
system("pause");
return 0;
}