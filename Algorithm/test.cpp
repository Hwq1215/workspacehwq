#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> a = {1,2,3,4};
    vector<int> b = {1,2,3};
    if(a==b) cout<<"true";
    else cout<<"false";
    system("pause");
    return 0; 
    }

    bool operator==(const vector<int> &one,const vector<int> &another){
        if(one.size() != another.size()) return false;
        else{
            for(int i = 0;i<one.size();i++){
                if(one[i]!=another[i]) return false;
            }
        }
        return true;
    } 