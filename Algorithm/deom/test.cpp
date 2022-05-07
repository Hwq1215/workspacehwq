#include<bits/stdc++.h>
using namespace std;

//search c pos in the string;
vector<int> search_c_pos(string str,char c){
    vector<int> c_pos;
    for(int i = 0;i<str.size();i++){
        if(str[i] == c){
            c_pos.push_back(i);
        }
    }
    return c_pos;
}