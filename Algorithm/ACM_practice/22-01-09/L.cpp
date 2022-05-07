#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
string input;
cin>>input;
for(int i = 0;i<input.size();i++){
    if(input[i]>='A'&&input[i]<'X'||(input[i]>='a'&&input[i]<'x')) input[i] = input[i] + 3;
    else input[i] = input[i] -23;
    if(input[i]>='a') input[i] -= 32;
    else if(input[i] >= 'A') input[i] +=32; 
}
reverse(input.begin(),input.end());
cout<<input;
system("pause");
return 0;
}