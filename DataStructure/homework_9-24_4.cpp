//�����ڳ��ȴ���1��ѭ���������У�����ͷ���Ҳ��ͷָ�룬pΪָ���������ĳ������ָ�룬��дһ���㷨ɾ���ý���ǰ�����

#include<vector>
#include<iostream>
using namespace std;

typedef struct list{
    int val;
    list *next;
}list;

//����һ��ѭ������
list* creatlistcycle(int n){  
    int i=0,num=0;
    if(n==1) return NULL;
    list* head=new list;
    list* p=head;
    for(i=0;i<n-1;i++){
        p->next=new list;
        p=p->next;
        cout<<"��"<<i+1<<"��:"<<endl;
        cin>>num;
        p->val=num;
    }
    cout<<"��"<<i+1<<"��"<<endl;
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
    cout<<"����������:";
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