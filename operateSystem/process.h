#ifndef process_head
#define process_head
#include<bits/stdc++.h>
using namespace std;
static int pid = 1001;
static long long run_time = 0;

#define process_Finished 2
#define process_Running 1
#define process_Ready 0

#define RUN_FINSHED 0
#define RUN_ONETIME 1

#define PSA 0
#define FCFS 1
#define RR 2
class Process{  
public:
    std::string process_name;             // 进程名字
    std::string process_id;                 // 进程id
    int process_priority;           // 进程优先级
    int process_state;              // 进程状态  0表示就绪，1表示运行，2表示结束 
    int process_arrival_time; // 进程到达时间
    int process_need_time;    // 进程需要的时间
    int process_used_time;    // 进程已经使用的时间

public:
    Process(std::string process_name, int process_priority, int process_need_time){
        this->process_name = process_name;
        this->process_id = std::to_string(pid++);
        this->process_priority = process_priority;
        this->process_arrival_time = run_time;
        this->process_state = process_Ready;
        this->process_need_time = process_need_time;
        this->process_used_time = 0;
    }

    Process(std::string process_name,int process_need_time){
        this->process_name = process_name;
        this->process_id = std::to_string(pid++);
        this->process_priority = 0;
        this->process_arrival_time = run_time;
        this->process_state = process_Ready;
        this->process_need_time = process_need_time;
        this->process_used_time = 0;
    }

    Process(const Process & process){
        this->process_name = process.process_name;
        this->process_id = process.process_id;
        this->process_priority = process.process_priority;
        this->process_arrival_time = process.process_arrival_time;
        this->process_state = process.process_state;
        this->process_need_time = process.process_need_time;
        this->process_used_time = process.process_used_time;
    }
    // prama
    // return process_need_time
    int process_run(int way,int use_time = 1){
        if(this->process_state == process_Ready){
            if(way == RUN_ONETIME){
                this->process_state = process_Running;;       
                if(this->process_need_time >= use_time){
                this->process_need_time -= use_time;
                this->process_used_time += use_time;
                }else{
                this->process_used_time += this->process_need_time;
                this->process_need_time = 0;
            }
                
                run_time += use_time;
            }else if(way == RUN_FINSHED){
                this->process_state = process_Finished;;       
                this->process_used_time += this->process_need_time;
                run_time += this->process_need_time;
                this->process_need_time = 0;  
            }else{
                cout<<"error"<<endl;
                return -1;
            }
            cout<<"进程"<<this->process_name<<"运行"<<endl;
            if(this->process_need_time <= 0){
            this->process_state = process_Finished;
            }else{
                this->process_priority ++;
            }
            return 0;
        }
        return -1;
    }

    std::string print_state(){
        if(this->process_state == process_Ready){
            return "就绪";
        }else if(this->process_state == process_Running){
            return "运行";
        }else if(this->process_state == process_Finished){
            return "结束";
        }
        return "未知error";
    }
    Process(){};
    ~Process(){};
};

struct process_node{
    struct Process process_data;
    struct process_node* next;
};

class table{
public:
    struct process_node* head;
    struct process_node* finish_head;
    
    table(){
        head = NULL;
        finish_head = NULL;
    }
    ~table(){};

public:
    void add_process(Process p){
        process_node* new_node = new process_node;
        new_node->process_data = p;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
        }else{
            process_node* p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = new_node;
        }
    }

    void put_process_to_finish(Process p){
        process_node* new_node = new process_node;
        new_node->process_data = p;
        new_node->next = NULL;
        if(finish_head == NULL){
            finish_head = new_node;
        }else{
            process_node* p = finish_head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = new_node;
        }
    }

    void delete_process(string id){
        if(head == NULL){
            return;
        }
        process_node* p = head;
        process_node* pre = NULL;
        while(p != NULL){
            if(p->process_data.process_id == id){
                if(pre == NULL){
                    head = p->next;
                }else{
                    pre->next = p->next;
                }
                delete p;
                return;
            }
            pre = p;
            p = p->next;
        }
    }

    void print_table(){
        process_node* p = head;
        printf("进程id 进程名字 进程状态 进程开始时间 进程所需时间 进程优先级数\n");
        while(p != NULL){
            printf(" %s     %s     %s     %5d   %10d        %5d\n",p->process_data.process_id.c_str(),
                                       p->process_data.process_name.c_str(),
                                       p->process_data.print_state().c_str(),
                                       p->process_data.process_arrival_time,
                                       p->process_data.process_need_time,
                                       p->process_data.process_priority);
            
            p = p->next;
        }
        process_node *p1 = finish_head;
        while (p1 != NULL) {
            printf(" %s     %s     %s     %5d   %10d        %5d\n",p1->process_data.process_id.c_str(),
                                       p1->process_data.process_name.c_str(),
                                       p1->process_data.print_state().c_str(),
                                       p1->process_data.process_arrival_time,
                                       p1->process_data.process_need_time,
                                       p1->process_data.process_priority);
            
            p1 = p1->next;
        }        
    }



    Process* get_process(string id){
        process_node* p = head;
        while(p != NULL){
            if(p->process_data.process_id == id){
                return &(p->process_data);
            }
            p = p->next;
        }
        return NULL;
    }

    int get_process_num(string process_id){
        process_node* p = head;
        int num = 0;
        while(p != NULL){
            if(p->process_data.process_id.compare(process_id)){
                num++;
            }
            p = p->next;
        }
        return num;
    }

    int run_process(string id){
        process_node* p = head;
        while(p != NULL){
            if(p->process_data.process_id == id){
                p->process_data.process_run(2);
                return 0;
            }
            p = p->next;
        }
        return -1;
    }

    int run(int flag = PSA,int part_time = 1){
        if(head == NULL){
            return -1;
        }else{
            back_state();
            if(flag == PSA){                    // PSA
            run_PSA();
            }else if(flag == FCFS){             // FCFS
            run_FCFS();
            }else if(flag == RR){
            run_RR(part_time);             // RR
            }
        }
        return 0;
    }   

    void run_PSA(){
        sort_by_priority();
        head->process_data.process_run(RUN_ONETIME);
        if(head->process_data.process_state == process_Finished){
            put_process_to_finish(head->process_data);
            head = head->next;
        }
    }
    void run_FCFS(){
        process_node *p = head;
        head->process_data.process_run(RUN_FINSHED);
        if(head->process_data.process_state == process_Finished){
            put_process_to_finish(head->process_data);
            head = head->next;
        }
    }

    void run_RR(int time_part) {
        process_node *p = head;
        head->process_data.process_run(RUN_ONETIME,time_part);
        if(head->process_data.process_state == process_Finished){
            put_process_to_finish(head->process_data);
            head = head->next;
        }else{
            while(p->next != NULL){
            p = p->next;
            }
            p->next = head;
            head = head -> next;
            p->next->next = NULL;
        }
    }

    void back_state(){
        process_node* p = head;
        while(p != NULL){
            if(p->process_data.process_state != process_Finished){
                p->process_data.process_state = process_Ready;
            }
            p = p->next;
        }
    }

    int sort_by_priority(){
        if(head == NULL || head->next == NULL){
            return 0;
        }
        process_node* p = head->next;
        process_node* pre = head;
        while(p != NULL){
            if(p->process_data.process_priority < pre->process_data.process_priority){
                Process temp = p->process_data;
                p->process_data = pre->process_data;
                pre->process_data = temp;
                p = head->next;
                pre = head;
                continue;
            }
            pre = p;
            p = p->next;
        }
        return 0;
    }
};

#endif /*process_head*/
