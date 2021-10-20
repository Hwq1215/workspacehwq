//试写一算法,对单链表实现就地逆置。
#include<vector>
#include<iostream>
using namespace std;

typedef struct list{
    int val;
    list *next;
}list;

list* creatlist(int n){
    int i=0,num=0;
    list* head=new list;
    head->next=NULL;
    list* p=head;
    for(i=0;i<n;i++){
        p->next=new list;
        p=p->next;
        cout<<"第"<<i+1<<"个:"<<endl;
        cin>>num;
        p->val=num;
    }
    p->next=NULL;
    return head;
}

void reback(list* head){
    list *p1=NULL,*p2=NULL;
    list *p=head->next;
    while(p){
        p2=p->next;   //记录原链表p->next
        head->next=p;
        p->next=p1;   //修改p所指后结点
        p1=p;         //记录前结点
        p=p2;         //引到原链表的下个结点
    }
}

int main(){
    int n=0;
    cout<<"请输入容量:";
    cin>>n;
    list *head=creatlist(n);
    reback(head);
    head=head->next;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    system("pause");
    return 0;
}