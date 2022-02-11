#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3;
string res;
string judge(char str1,char str2){
    string ins;
    if(str1<='9' && str1>='0' && str2 > str1+1 && str2<='9'){
        for(char ch = str1 +1;ch<str2;ch++){
            int i = p2;
            while(i--){
                if(p1 == 3) ins.push_back('*');
                else ins.push_back(ch);         
            }
        }
    }else if(str1 <='z' && str1 >='a' && str2>str1 +1 && str2<='z'){
        for(char ch = str1 +1;ch<str2;ch++){
            int i = p2;
            while(i--){
                if(p1 == 3) ins.push_back('*');
                else if(p1 == 2) ins.push_back(ch-32);
                else ins.push_back(ch);         
            }
        }
    }else if(str1 == str2-1){
        ins = "";
    }else{
        ins.push_back('-');
    }
    if(p3 == 2) reverse(ins.begin(),ins.end());
    return ins;
}

int main(){
char str[105];
cin>>p1>>p2>>p3;
scanf("%s",str+1);
for(int i = 1;str[i]!='\0';i++){
    if(str[i] != '-') res.push_back(str[i]);
    else if(str[i] =='-'&&(str[i-1]=='-'||str[i+1]=='-'||i==1||str[i+1]=='\0')) res.push_back('-');
    else if(str[i] == '-') res.append(judge(str[i-1],str[i+1]));
}
cout<<res<<endl;
system("pause");
return 0;
}