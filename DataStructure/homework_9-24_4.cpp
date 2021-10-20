//假设在长度大于1的循环单链表中，既无头结点也无头指针，p为指向该链表中某个结点的指针，编写一个算法删除该结点的前驱结点

#include<vector>
#include<iostream>
using namespace std;

typedef struct list{
    int val;
    list *next;
}list;

//设置一个循环链表
list* creatlistcycle(int n){  
    int i=0,num=0;
    if(n==1) return NULL;
    list* head=new list;
    list* p=head;
    for(i=0;i<n-1;i++){
        p->next=new list;
        p=p->next;
        cout<<"第"<<i+1<<"个:"<<endl;
        cin>>num;
        p->val=num;
    }
    cout<<"第"<<i+1<<"个"<<endl;
    cin>>head->val;
    p->next=head;
    return head;
}

void det_front(list* p){
    list *mark=p,*p1;
    while(p->next!=mark){
        p1=p;
        p=p->next;
    }
    p1->next=mark;
    delete p;
}

int main(){
    int n=0;
    cout<<"请输入容量:";
    cin>>n;
    list* head=creatlistcycle(n);
    list* p=head->next;
    det_front(p);
        while(p){
        cout<<p->val<<" ";
        p=p->next;
    }
    system("pause");
    return 0;
}