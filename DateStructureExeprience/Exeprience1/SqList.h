#include<iostream>
using namespace std;
#define DEFAULT_SIZE 1000 // 缺省元素个数
#define DEFAULT_INFINITY 100000 // 缺省无穷大
// 顺序表模板类的申明
template <class ElemType>
class SqList
{
public:
// 顺序表的数据成员
int length=0; // 顺序表的当前长度
int maxLength; // 顺序表的最大容量
ElemType *data; // 元素存储空间的首地址
public:
// 顺序表的函数成员
SqList(int size = DEFAULT_SIZE){ 
    if(size>DEFAULT_INFINITY){
        std::cout<<"use too much memory";
    } 
    else{
        data=new ElemType[size];
        maxLength=size;
        length=0;
    }
} // 构造一个空表

SqList(ElemType v[], int n=1, int size = DEFAULT_SIZE){
    if(size>DEFAULT_INFINITY){
        std::cout<<"use too much memory";
    }     
    else if(n>size){
        std::cout<<"memory over";
    } 
    else{
        length=n;
        maxLength=size;
        ElemType *data=new ElemType[size];
        ElemType *adr=data; 
        int i=0;
        for(i=0;i<n;i++){
        *adr=v[i];
        if(i!=n-1) adr++;
    }
    }
} // 根据数组 v 的内容构造顺序表

virtual ~SqList(){}; // 析构函数

int GetLength() const{
    return length;
} // 取顺序表长度
// 判断顺序表是否为空
bool IsEmpty() const{
    if(length) return false;
    else return true;
} // 判断顺序表是否为空

int Get(int i, ElemType &e) const{
    if(i>length&&i<1) return 0;
    ElemType *s=data+i-1;
    e=*s;
    }// 取顺序表中第 i 个元素的值

int Set(int i, const ElemType &e){
    if(i>length&&i<1) return 0;
    ElemType *s=data+i-1;
    *s=e;
} // 修改顺序表中第 i 个元素的值

int Delete(int i){
    if(i>length&&i<1) return 0;
    ElemType *s=data+i-1;
    while(i!=length){
    *s=*(s+1);
    s++;
    i++;
    }   
    length--;
    return 1;
}   // 删除顺序表中第 i 个元素

int Insert(int i,const ElemType &e){
    if(i>length+1&&i<1) return 0; 
    length++;
    int j=length-1;
    while(j!=i-1){
        this->data[j]=this->data[j-1];
        j--;
    }
    this->data[i-1]=e;
} // 在顺序表第 i 个位置插入元素 

int clear(int size = DEFAULT_SIZE){
    length=0;
    delete [] data;
    data=new ElemType[size];
    return 1;
}//清除
};

