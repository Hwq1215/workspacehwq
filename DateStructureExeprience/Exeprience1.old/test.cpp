#include<iostream>
#include"LinkList.h"
#include"student.cpp"
using namespace std;

int main(){
    student member;
    student e={"Tom","0122004920104",3.6};
    student s={"Jack","0122004920136",2.9};
    LinkList<student> a;
    cout<<a.GetLength()<<endl
    ;
    a.Set(1,e);
    a.Get(1,member);
    cout<<member.num<<endl<<member.name<<endl<<member.gap;
    a.Insert(2,s);
    a.Get(2,member);
    cout<<endl<<member.num<<endl<<member.name<<endl<<member.gap;
    a.Delete(1);
    a.Get(1,member);
    cout<<endl<<member.num<<endl<<member.name<<endl<<member.gap;
    system("pause");
}