#include<bits/stdc++.h>
#include"process.h"
using namespace std;

class test{
    public:
        table testTable;
        test(){
            Process p1("p1",1);
            run_time += 1;
            Process p2("p2",2);
            run_time += 1;
            Process p3("p3",3);
            run_time += 1;
            Process p4("p4",12);
            run_time += 1;
            Process p5("p5",5);
            run_time += 1;
            Process p6("p6",2);
            run_time += 1;
            Process p7("p7",1);
            run_time += 1;
            Process p8("p8",8);
            run_time += 1;
            Process p9("p9",12);
            testTable.add_process(p1);
            testTable.add_process(p2);
            testTable.add_process(p3);
            testTable.add_process(p4);
            testTable.add_process(p5);
            testTable.add_process(p6);
            testTable.add_process(p7);
            testTable.add_process(p8);
            testTable.add_process(p9);
        }
        ~test(){
            testTable.~table();
        }
        void print_all_process(){
            testTable.print_table();
        }
};

int main(){
    system("chcp 65001");
    system("cls");
    test t;
    t.print_all_process();
    while(1){
        system("cls");
        string str;
        int al_choose;
        cout<<"要运行的进程编号,输入set设定默认算法,输入run(run_all)进行默认算法调度,输入search查看进程,输入exit退出"<<endl;
        cout<<"$";
        cin>>str;
        if(str.compare("exit")==0){
            cout<<"退出"<<endl;
            break;
        }else if(str.compare("search")==0){
            t.print_all_process();
        }else if(str.compare("run")==0){
            if(t.testTable.run(al_choose) == -1){
                cout<<"没有可以运行的进程"<<endl;
            }
            t.print_all_process();
        }else if(str.compare("run_all")==0){
            while(t.testTable.run(al_choose) != -1){
                t.print_all_process();
            }
        }else if(str.compare("set")==0){
            system("cls");
            cout<<"输入算法PSA,FCFS,RR"<<endl;
            cout<<"$";
            cin>>str;
            if(str.compare("PSA")==0){
                al_choose = PSA;
            }else if(str.compare("FCFS")==0){
                al_choose = FCFS;
            }else if(str.compare("RR")==0){
                al_choose = RR;
            }else{
                cout<<"输入错误"<<endl;
                continue;
            }
        }else{
            if(t.testTable.run_process(str) == 0){
                cout<<"调度成功" <<endl;
            }else{
                cout<<"命令或进程不存在"<<endl;
            }
        }
       system("pause");
    }
    system("pause");

return 0;
}