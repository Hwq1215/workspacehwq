//假设铁道进行车厢调度，火车调度站的入口处有n节硬席和软席车厢（分别用H和S来表示）等待调度。
//试编写算法，输出这n节车厢的进行调度的序列，使所有的软席车厢都被调度到硬席车厢的前面。
#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    vector<char> a;
    int top;
    int stacksize;
}stack;

void revalue(stack &s){
    s.top=-1;
    s.stacksize=0;
}

void go_back(stack &s,char c){
    s.a.push_back(c);
    s.top++;
    s.stacksize++;
}

void reduce(stack &s){
    s.a.pop_back();
    s.top--;
    s.stacksize--;
}
vector<char> rejust(int n){
    stack train,s;
    revalue(train);
    revalue(s);
    char c;
    int i=0;
    for(i=0;i<n;i++){
        cin>>c;
        if(c=='S') go_back(train,c);
        else if(c=='H') go_back(s,c);
    }
    for(i=s.top;i>=0;i--){
        c=s.a[s.top];
        go_back(train,c);
        reduce(s);
    }
    for(i=0;i<=train.top;i++){
        cout<<train.a[i];
    }
    return train.a;
}

int main(){
    int n;
    cout<<"how many train?";
    cin>>n;
    rejust(n);
    system("pause");
}