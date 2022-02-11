#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidWords(string sentence) {
        int res = 0;
        char *p,s[1007];
        char *pattern = " ";
        strcpy(s,sentence.c_str());
        p = strtok(s,pattern);
        while(p){
            int cnt = 0;
            int i = 0;
            for(i = 0;p[i]!='\0';i++){
                if(p[i]<='9'&&p[i]>='0'){
                    break;
                }
                else if(p[i] == '-'){
                    if(i==0 || p[i+1]=='\0'||(p[i-1]<'a'||p[i-1]>'z'||p[i+1]<'a'||p[i+1]>'z')) break;
                    else{
                        if(cnt) break;
                        cnt++;
                        }
                }else if((p[i]=='!'||p[i]=='.'||p[i]==',') && p[i+1]!='\0'){
                    break;
                }
            }
            if(p[i]=='\0') res++; 
            p = strtok(NULL,pattern);
        }
        return res;
    }
};
int main(){

system("pause");
return 0;
}
