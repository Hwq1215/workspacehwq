//��дһ�㷨,�Ե�����ʵ�־͵����á�
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
        cout<<"��"<<i+1<<"��:"<<endl;
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
        p2=p->next;   //��¼ԭ����p->next
        head->next=p;
        p->next=p1;   //�޸�p��ָ����
        p1=p;         //��¼ǰ���
        p=p2;         //����ԭ������¸����
    }
}

int main(){
    int n=0;
    cout<<"����������:";
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