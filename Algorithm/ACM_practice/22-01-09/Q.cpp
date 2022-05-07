#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char ch = ' ';
    int cnt = 1;
    for(char c :s){
        if(c == ch){
            cnt++;
        }else if(c != ch){
            if(n == 1){
                cout<<c;
                system("pause");
                return 0;
            }else if(cnt >= n){
                cout<<ch;
                system("pause");
                return 0;
            } 
            cnt = 1;
        }
        ch = c;
    }
    if(cnt >= n){
        cout<<ch;
        system("pause");
        return 0;
    }
    cout<<"No";
system("pause");
return 0;
}