#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int total;
    int n;
    cin>>total;
    for(int k = 0;k<total;k++){
        int cnt = 0;
        cin>>n;
        for(int i = 1;i<=n;i++){
        vector<int > yizi;
        for(int j = 1;j<sqrt(n)+1;j++){
            if(i%j == 0){
                yizi.push_back(j);
                if( j != i/j) yizi.push_back(i/j);
            }
        }
        sort(yizi.begin(),yizi.end());
        if(yizi[yizi.size()-1]%yizi[yizi.size()/2]==0){
            cnt ++;
        }
    }
    cout<<cnt<<endl;
    }
system("pause");
return 0;
}