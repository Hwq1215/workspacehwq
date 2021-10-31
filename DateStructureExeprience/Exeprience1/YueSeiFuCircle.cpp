#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

class CycleCircle{

    protected:
    vector<int> member;
    int length=0;
    string putstr;

    public:
//算法部分
    int set_member(int n){
        if(n>0){
            length=n;
            member.resize(n);
            set_frist_value();
            return 1;
        }
        else{
            return 0;
        }
    }

    int choose(int condition){
        int cnt=length;
        int already=0;
        int last=0;
        for(int i=0;cnt;i++){
            for(int j=0;j<length;j++){
                if(member[j]==1){
                    already++;
                }
                if(already==condition){
                    putstr.append(changeToString(j+1));
                    putstr.append(" ");
                    member[j]=0;
                    already=0;
                    cnt--;
                    if(cnt==0) return j+1;
                }
            }
        }
    }
//
    bool is_empty(){
        return member.empty();
    }

    int length_is() const{
        return length;
    }

    string result(){
        return putstr;
    }

    private:
    string changeToString(int value){
        string str;
        int num=0;
        while(value)
        {
            num=value%10;
            str+=(char)(num+'0');
            value/=10;
        }
        reverse(str.begin(),str.end());
        return str;
    }

    void set_frist_value(){
        for(int i=0;i<member.size();i++){
            member[i]=1;
        }
    }
};

int main(){
    system("chcp 65001");
    int total = 0;
    int condition = 1;
    cout<<"一共几个个体"<<endl;
    cin>>total;
    cout<<"每过多少出列"<<endl;
    cin>>condition;
    CycleCircle cc;
    cc.set_member(total);
    int LastOne=cc.choose(condition);
    cout<<"顺序是"<<cc.result()<<endl;
    cout<<"最后一个是"<<LastOne<<endl;
    system("pause");
}