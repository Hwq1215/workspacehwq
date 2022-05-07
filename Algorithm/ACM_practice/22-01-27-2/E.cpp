#include<bits/stdc++.h>
using namespace std;
string ans;
string ins;
int main(){
    int zero_flag = 0,zero_num = 0,ji = -1;
    for(int i = 0;i<10;i++ ){
        int inp = 0;
        cin>>inp;
        if(i == 0){
            zero_num = inp/2;
            if(inp>0) zero_flag = 1;
            if(inp%2){
                ji = 0;
            }
        }else if(inp%2 == 0){  
            for(int l = 0;l<inp/2;l++){
                ins.push_back(i+'0');
                while(zero_num>0){
                    zero_num--;
                    ins.push_back('0');
                }
            }
        }else{
            if(ji != -1){
                cout<<-1<<endl;
                system("pause");
                return 0;
            }else{
                for(int l = 0;l<inp/2;l++){
                ins.push_back(i+'0');
                while(zero_num>0){
                    zero_num--;
                    ins.push_back('0');
                }
                }
                ji = i;
            }
        }
    }
    if(ins.compare("") == 0 && ji == 0){
        cout<<0<<endl;
        return 0;
    }else if(ins.compare("")==0){
        cout<<-1<<endl;
        system("pause");
        return 0;
    }else{
        ans.append(ins);
        reverse(ins.begin(),ins.end());
        if(ji!=-1) ans.push_back(ji+'0');
        ans.append(ins);
    }
    cout<<ans<<endl;
system("pause");
return 0;
}