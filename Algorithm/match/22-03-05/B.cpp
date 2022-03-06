#include<bits/stdc++.h>
#include<map>
using namespace std;

int main(){
    map<int,int> letter;
    string in;
    cin>>in;
    for(int i = 0;i<in.size();i++){
        letter[in[i]-'a'] ++;
    }
    string out;
    for(int i = 0;i<26;i++){
        out.append(letter[i],'a'+i);
    }
    cout<<out;
system("pause");
return 0;
}
