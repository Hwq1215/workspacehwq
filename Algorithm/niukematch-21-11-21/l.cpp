#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    string one[n];
    string letter[m];
    vector<vector<int>> mark(n);
    for(int i = 0;i<n;i++){
        cin>>one[i];
    }
    for(int i = 0;i<m;i++){
        cin>>letter[i];
        for(int j = 0;j<n;j++){
            if(letter[i]==one[j]){
                mark[j].push_back(i);
            }
        }
    }
    
}
