#include<bits/stdc++.h>
using namespace std;

int main(){
    int in;
    cin>>in;
    in %= 14;    
    for(int i = 0;i<7;i++){
        in = (in*in) %14;
    }
    while(in/14){
        in %= 14;
    }
    cout<<in<<endl;
system("pause");
return 0;
}