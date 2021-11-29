#include<iostream>
#include<vector>
using namespace std;
typedef int type;
class student{
    public:
    string name;
    type value;
};
class node{
    public:
    string name;
    type value;
    node *next = nullptr;
};
class Mymap{
    public:
    node *data;
    Mymap(int num,vector<student> s){
        int total = searchBigNum(num*4/3);
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
    private:
    int getPosition(string input,int total){//获取字符串对应的位置
        return ((int)input[0]+(int)input[input.size()-1])%total;
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
    vector<student> s = {s1,s2};
    Mymap hash(2,s);
    system("pause");
}