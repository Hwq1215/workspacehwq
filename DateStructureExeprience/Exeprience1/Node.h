//Node.h
// 结点类
template <class ElemType>
struct Node 
{// 数据成员:
ElemType data; // 数据域
Node<ElemType> *next; // 指针域
// 构造函数:
Node(){} // 无参数的构造函数
Node(ElemType e, Node<ElemType> *link = NULL){
    if(link==NULL){
        cout<<"error";
        }
    else{
        link->data=e;
    }
}// 已知数数据元素值和指针建立结构
*Node newNode(ElemType e){
    Node *head=new Node;
    head->data=e;
} 
};
