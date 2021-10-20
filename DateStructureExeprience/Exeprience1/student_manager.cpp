#pragma once
#include"SqList.h"
#include<iostream>
#include"student.cpp"
using namespace std;

int main(){
    system("chcp 65001");
    char order;
    student member,member1;
    SqList<student> stu;
    student *temp=stu.data;
    while(1){
        fflush(stdin);
        while(1){
        order='0';
        cout<<endl<<"1.显示"<<endl<<"2.录入"<<endl<<"3.查找"
        <<endl<<"4.删除"<<endl<<"5.更新"<<endl<<"6.统计"
        <<endl<<"7.排序"<<endl<<"8.清空"<<endl<<"请选择你的操作:";
     order=getchar();
        if (order>'8'||order<'1'){
            cout<<endl<<"格式错误，重新输入!"<<endl;
            }
        else{
            fflush(stdin);
            break;
        }
        fflush(stdin);
    }
    int stay,mark,flag_exist,cnt,m,n;
    double max;
    m=n=1;
    stay=mark=0;
    flag_exist=1;
    max=0;
    switch(order){
        case '1'://显示 
            if(stu.IsEmpty()){
                cout<<"没有学生"<<endl;
            }
            else{
                for(int i=1;i<=stu.GetLength();i++){
                    stu.Get(i,member);
                    cout<<i<<".学号:"<<member.num<<endl
                    <<"  姓名:"<<member.name<<endl
                    <<"  绩点:"<<member.gap<<endl;                                     
                }
            }
            break;
        
        case '2':
                cout<<"学号:";
                cin>>member.num;
                cout<<"姓名:";
                cin>>member.name;
                cout<<"绩点:";
                cin>>member.gap;
                stu.Insert(stu.GetLength()+1,member);
            break;

        case '3':
            if(stu.IsEmpty()){
                cout<<"没有学生"<<endl;
            }
                else{
                    cout<<"学号:";
                    cin>>member.num;
                    for(int i=1;i<=stu.GetLength();i++){
                    if(temp->num==member.num){
                        cout<<"是第"<<i<<"个学生"<<endl;
                        flag_exist=0;
                        }
                    if(i!=stu.GetLength())temp++;
                    }
                if(flag_exist) cout<<"没有这个学生";      
                temp=stu.data;}
            break;
                
        case '4':
                if(stu.IsEmpty()){
                cout<<"没有学生"<<endl;
                }
                else{cout<<"你想删除第几个学生(use numbers):";
                cin>>stay;
                stu.Delete(stay);}
            break;

        case '5':
            if(stu.IsEmpty()){
                cout<<"没有学生"<<endl;
            }
                else{
                cout<<"你想更新第几个学生(use numbers):";
                cin>>stay;
                cout<<"1.学号"<<endl<<"2.姓名"<<endl<<"3.绩点"<<endl;
                cin>>mark;
                stu.Get(stay,member);
                switch(mark){
                    case 1:
                        cout<<"学号是:";
                        cin>>member.num;
                        stu.Set(stay,member);
                        break;
                    case 2:
                        cout<<"姓名是:";
                        cin>>member.name;
                        stu.Set(stay,member);
                        break;
                    case 3:
                        cout<<"绩点是:";
                        cin>>member.gap;
                        stu.Set(stay,member);
                        break;
                    default:
                        cout<<"输入不合规范"<<endl;
                }
                }
            break;
        case '6':
                cout<<"一共有"<<stu.GetLength()<<"名学生"<<endl;
            break;
        case '7':
            if(stu.IsEmpty()){
                cout<<"没有学生"<<endl;
            }
            else if(stu.GetLength()==1){
                cout<<"只有一个学生"<<endl;
            }
            else{
                for(m = 1;m<stu.GetLength();m++){
                    for(n = m;n<=stu.GetLength();n++){
                        stu.Get(n,member);
                        if(n==m||member.gap>max){
                            max=member.gap;
                            mark=n;
                        }
                    }
                    stu.Get(mark,member);
                    stu.Get(m,member1);
                    stu.Set(m,member);
                    stu.Set(mark,member1);             
                }
                for(int i=1;i<=stu.GetLength();i++){
                    stu.Get(i,member);
                    cout<<i<<".学号"<<member.num<<endl
                    <<"  姓名"<<member.name<<endl
                    <<"  绩点"<<member.gap<<endl;                                     
                }
                }
            break;
        case '8':
                if(stu.clear()){
                    cout<<"*****数据已清空*****"<<endl;
                }
            break;
    }
    }
}
