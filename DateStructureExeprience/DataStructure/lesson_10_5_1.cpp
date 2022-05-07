//循环队列
#include<iostream>
#define m 7
using namespace std;
typedef struct line{
    int elm[m];
    int front;
    int rear;
};
line* creatline(){
    line*p=new line;
    p->rear=0;
    p->front=0;
    return p;
}
void inside(line& a,int x){
    if((a.rear+1)%m==a.front){
        a.elm[a.rear]=x;
        cout<<"FULL";
    }
    else{
        a.elm[a.rear]=x;
        a.rear=(a.rear+1)%m;
    }
}
int outside(line& a){
    int x;
    if(a.front==a.rear) cout<<"EMPTY";
    else {
        x=a.elm[a.front];
        a.front=(a.front+1)%m;
    }
    return x;
}
int main(){
    line*p = creatline();
    for(int i=1;i<8;i++){
        inside(*p,i);
    }
    int i=p->front;
    do{
        if(p->front==p->rear) break;
        cout<<p->elm[i];
        i=(i+1)%m;
        }while(i!=p->front);
    outside(*p);
    i=p->front;
    do{
        if(p->front==p->rear) break;
        cout<<p->elm[i];
        i=(i+1)%m;
        }while(i!=p->front);
    system("pause");
    return 0;
    }



/*链表队列注意出队时加入if(front_>next==front) rear=front*/