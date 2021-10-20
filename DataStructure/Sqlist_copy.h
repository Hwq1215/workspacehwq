#include<iostream>
#define DEFAULT_SIZE 1000 // 缺省元素个数
#define DEFAULT_INFINITY 1000000 // 缺省无穷大
// 顺序表模板类的申明
class ElemType{
    public:
    std::string name;
    std::string num;
    double gap;
};
// 顺序表模板类的申明
template <class ElemType>
class SqList
{
protected:
// 顺序表的数据成员
int length; // 顺序表的当前长度
int maxLength; // 顺序表的最大容量
ElemType *data; // 元素存储空间的首地址
public:
// 顺序表的函数成员

SqList(int size = DEFAULT_SIZE){ 
    if(size>DEFAULT_INFINITY){
        cout<<"use too much memory";
    } 
    else{
        ElemType *data=new ElemType[size];
        maxLength=size;
    }
} // 构造一个空表
SqList(ElemType v[], int n=1, int size = DEFAULT_SIZE){
    if(size>DEFAULT_INFINITY){
        cout<<"use too much memory";
    }     
    else if(n>size){
        cout<<"memory over";
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
virtual ~SqList(); // 析构函数
int GetLength() const{
    return length;
} // 取顺序表长度
bool IsEmpty() const{
    if(length) return false;
    else return true;
} // 判断顺序表是否为空
int Locate(const ElemType &e) const{
    ElemType *s=data;
    int i=1;
    for(i=1;i<=length;i++){
        if(e.num==s->num) return i;
        s++; 
    }
    if(i==length+1) return -1;
} // 元素定位，求指定元素在顺序表中的位置
string Getnum(int i,ElemType &e) const{
    if(i>length&&i<1) {
        cout<<"ElemType no exist";
        return "null";
        }
    ElemType *s=data;
    s+=i-1;
    return s->num;
} // 取顺序表中第 i 个元素的值(学号)
string Getname(int i,ElemType &e) const{
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return "null";
        }
    ElemType *s=data;
    s+=i-1;
    return s->name;
}
double Getgap(int i,ElemType &e) const{
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return 0.0;
        }
    ElemType *s=data;
    s+=i-1;
    return s->gap;
}
int Setnum(int i, string newnum){
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return 0;
        }
    ElemType *s=data;
    s+=i-1;
    s->num=newnum;
    return 1;
} // 修改顺序表中第 i 个元素的值
int Setname(int i, string newname){
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return 0;
        }
    ElemType *s=data;
    s+=i-1;
    s->name=newname;
    return 1;
} // 修改顺序表中第 i 个元素的值
int Setgap(int i, double newgap){
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return 0;
        }
    ElemType *s=data;
    s+=i-1;
    s->gap=newgap;
    return 1;
} // 修改顺序表中第 i 个元素的值
int Delete(int i){
    if(i>length&&i<1){
        cout<<"ElemType no exist";
        return 0;
        }
    ElemType *s=data;
    s+=i-1;
    while(i!=length){
    *s=*(s+1);
    s++;
    i++;
    }   
    free(s);
    length--;
    return 1;
}   // 删除顺序表中第 i 个元素
int Insert(int i,const ElemType&e){
    if(i>length+1&&i<1){
        cout<<"ElemType no exist";
        return 0;
        }
    length++;
    ElemType *s=data,*end=data+length-1;
    s+=i-1;
    while(end!=s){
        *end=*(end-1);
        end--;
    }
    *s=e;
} // 在顺序表第 i 个位置插入元素 
//排序
void numsort(){
    ElemType *s=data;

}
};

