#include "Node.h"// 结点类
// 单链表类
#include<iostream>
#define maxsize 100;
using namespace std;

template <class ElemType>
class LinkList 
{
protected:
// 单链表的数据成员
Node<ElemType> *head;// 头结点指针
int length=0; // 单链表长度
public:
// 单链表的函数成员
LinkList(){
    head=new Node<ElemType>;
    length++;
}; // 无参数的构造函数
LinkList(ElemType v[], int n){
    head=new Node<ElemType>();
    Node<ElemType> *p=head;
    length++;
    for(int i=0;i<n-1;i++){
        p->data=v[i];
        length++;
        p->next=new Node<ElemType>();
        p=p->next;
    }
    p->data=v[n-1];
} // 有参数的构造函数
virtual ~LinkList(); // 析构函数
Node<ElemType>* GetHead(){
    return head;
}//获得头指针
int GetLength() const{
    return length;
} // 求单链表长度
bool IsEmpty() const{
    if(!length) return true;
} // 判断单链表是否为空a
int Locate(const ElemType &e) const{
    int i=1;
    Node<ElemType> *p=head;
    while(p){
        if(p->data==e){
            return i;
        }
        p=p->next;
    }
    return -1;
} // 元素定位
int Get(int index, ElemType &e) const{
    int i=1;
    if(index>length){
        return -1;
    }
    else{Node<ElemType> *p=head;
    while(i<index){p=p->next;}
    e=p->data;}
    return 1;
} // 求指定位置的元素
int Set(int index, const ElemType &e){
    int i=1;
    if(index>length){
        return -1;
    }
    else{Node<ElemType> *p=head;
    while(i<index){p=p->next;}
    p->data=e;}
    return 1;
} // 设置指定位置的元素值
int Delete(int index){
    int i=1;
    if(index>length){
        return -1;
    }
    else if(index==1&&length==1){
        delete head;
        head=new Node<ElemType>();
    }
    else if(index==1){
        Node<ElemType> *m=head,*p=head->next;
        delete m;
        head=p;
    }
    else if(index==length){
        Node<ElemType> *p=head,*m;
        while(p->next){
            m=p;
            p=p->next;
        }
        m->next=NULL;
        delete p;
    }
    else{
        Node<ElemType> *p=head,*n;
        while(i<index){
            n=p;
            p=p->next;
            }
        n=p;
        p=p->next;
        }
        length--;
        return 1;
} // 删除元素
int Insert(int index, const ElemType &e){
    Node<ElemType> *p=head;
    Node<ElemType> *newNode=new Node<ElemType>();
    newNode->data=e;
    if(index==1){     
        newNode->next=head;
        head=newNode;
    }
    else if(index==length){
        while(p->next) p=p->next;
        
    }
} // 在制定位置插入元素
};
