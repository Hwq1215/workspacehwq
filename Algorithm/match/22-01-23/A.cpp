#include<bits/stdc++.h>
using namespace std;

int main(){
string input = "";
cin>>input;
int a,b;
cin>>a>>b;
char ins = input[a-1];
input[a-1] = input[b-1];
input[b-1] = ins; 
system("pause");
return 0;
}