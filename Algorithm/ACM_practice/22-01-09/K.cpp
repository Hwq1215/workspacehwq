#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
string input,output="";
cin>>input;
for(char c:input){
    if(c == 'A') output.append("T");
    else if(c == 'T') output.append("A");
    else if(c == 'C') output.append("G");
    else if(c == 'G') output.append("C");
}
cout<<output;
system("pause");
return 0;
}
