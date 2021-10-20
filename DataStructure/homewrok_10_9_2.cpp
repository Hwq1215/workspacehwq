//假设称正读和反读都相同的字符序列为“回文”，例如，‘abba’和‘abcba’是回文，
//‘abcde’和‘ababab’则不是回文。
//试写一个算法判别读入的一个以‘@’为结束符的字符序列是否是“回文”。
//（要求：同时使用栈和队列两种结构）
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//栈
typedef struct{
    vector<char> a;
    int top;
    int size;
}stack;

void revalue(stack &s){
    s.top=-1;
    s.size=0;
}

void go_back(stack &s,char c){
    s.a.push_back(c);
    s.top++;
    s.size++;
}

char delback(stack &s){
    char c = s.a[s.top];
    s.top--;
    s.size--;
    s.a.pop_back();
    return c;
}

//队列
typedef struct queue{
    vector<char> a;
    int front;
    int rear;
};

void pushin(queue &q,char c){
    q.a.push_back(c);
    q.rear++;
}

char getout(queue &q){
    char m=q.a[q.front];
    q.front++;
    return m; 
}

int main(){
        char str[99];
    char c=0;
    queue q;
    q.front=0;
    q.rear=0;
    stack s;
    revalue(s);
    int i=0;
    while((c=getchar())!='@'){
        go_back(s,c);
        pushin(q,c);
    }
    for(i=s.top;i>=0;i--){
        if(delback(s)!=getout(q)){
            cout<<"isn't Palindromic_String)"<<endl;
            break;
        }
    }
    if(i==-1){
        cout<<"is (Palindromic_String)"<<endl;
    }
    system("pause");
    getchar();
    }
    
