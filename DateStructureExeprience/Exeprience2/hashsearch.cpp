#include<iostream>
#include<vector>
using namespace std;
typedef int type;
class student{
    public:
    string name;
    type value;
    student(string a,type b){
        this->name = a;
        this->value = b;
    }
};
class node{
    public:
    string name;
    type value;
    node *next = nullptr;
};
class Mymap{
    private:
    int length = 0;
    public:
    node *data;
    Mymap(int num,vector<student> s){
        int total = searchBigNum(num*4/3);
        length = total;
        data = new node[total];
        for(int i = 0;i<s.size();i++){
            node* OneNode = new node;
            OneNode->name = s[i].name;
            OneNode->value = s[i].value;
            node* p = &data[getPosition(s[i].name,total)];
            while( p->next != nullptr){
                p = p->next;
                }
            p->next = OneNode;
        }
    }
    student search(string input){
        student stu("0",-1);
        if (length == 0) return stu;
        node *p = &data[getPosition(input,length)];
        p = p->next;
        while( p!= nullptr){
            if(p->name == input){
                stu.name = p->name;
                stu.value = p->value;
                return stu;
            }
            p = p->next;
        }
        return stu;
    }
    private:
    int getPosition(string input,int total){//获取字符串对应的位置
        return (((int)input[0])*input.size()+(int)input[input.size()-1])%total;
    }
    int searchBigNum(int temp){//寻找最大质数
        int result = 2;
        while(temp!=2){
            if(isUnum(temp)){
                result = temp;
                break;
            }
            temp--;
        }
        while(!isUnum(++result));
        return result;
    }
    inline bool isUnum(int input){
        for(int i = 2;i<input;i++){
                if(input%i==0) return false;
            }
            return true;
    }
};

int main(){
    student s1 = {"jack",60};
    student s2 = {"mary",70};
    student s3 = {"jcnk",82};
    student s4 = {"jop",88};
    vector<student> s = {s1,s2,s3,s4};
    for(int i = 0;i<s.size();i++ ){
        cout<<s[i].name<<"  "<<s[i].value<<endl;
    }
    Mymap hash(4,s);
    string in;
    cout<<"you want whose scores?"<<endl;
    cin>>in;
    student j = hash.search(in);
    if(j.value == -1) cout<<"no found"<<endl;
    else cout<<j.name<<"  "<<j.value;                                                                                                                                                   
    system("pause");
}