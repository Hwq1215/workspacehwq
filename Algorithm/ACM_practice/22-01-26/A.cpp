/*
#include<bits/stdc++.h>
using namespace std;
int maxN = 1e6+7;
int main(){
while(true){
    int cnt = 1;
    string str;
    str.resize(maxN);
    scanf("%s",&str[0]);
    if(str[0]=='.'){
        return 0;
    }
    string tag = "";
    int pos = 1;
    tag.push_back(str[0]);
    while(str[pos]!='\0'){
        if(str.substr(pos,tag.size()).find(tag) == str.npos){
            cnt = 1;
            int native_size = tag.size();
            tag.append(str.substr(pos,tag.size()));
            pos = pos + native_size;
        }else{
            cnt++;
            pos += tag.size();
        }
    }
    cout<<cnt<<endl;
}
return 0;
}
//原来的想法
*/
//kmp算法
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e6+7;
int next1[maxN];
void kmp(char * a,int n){
    int i = 1,j = 0; 
    next1[0] = 0;j = next1[i-1];
    while(i<n){
        while(j>0 && a[i]!=a[j]){
            j = next1[j-1];
        }
        if(a[i]==a[j])
        j++;
        next1[i] = j;
        i++;
    } 
}
int main(){
    while(true){
        char str[maxN]; 
        scanf("%s",str);
        if(str[0]=='.'){
            return 0;
        }
        int len = strlen(str);
        kmp(str,len);
        int i = len -1;
        for(i = len-1;i>0;i--){
            if(next1[i]==0){
                break;
            }
        }
        if(len%(i+1)==0){
            cout<<len/(i+1)<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    
system("pause");
return 0;
}