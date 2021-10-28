#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

template<class element>
class Node{
    public:
    element data;
    Node<element> *next=NULL;
};

template<class element>
class List{
    private:
    Node<element> *head=new Node<element>();
    int length=1;
    
    public:
    void set_length(int n){
        int i=n-1;
        Node<element> *p1,*p;
        if(n!=1){
            p=new Node<element>();
            head->next=p;
            length=n;
            }
        while(--i){
            p1=new Node<element>();
            p->next=p1;
            p=p->next;
        }
    }
    void set_value(element value,int order){
        Node<element> *p=head;
        if(order<1) return;
        for(int i=1;i<order&&p->next;i++){
            p=p->next;
        }
        p->data=value;
    }
    
    int get_length(){
        return length;
    }
    Node<element>* get_head(){
        return head;
    }
    Node<element>* Lastone(){
        Node<element> *p=head;
        while(p->next){
            p=p->next;
        }
        return p;
    }
};


class formal{
    public:
    List<int> result(List<int> &a,List<int> &b){
        List<int> output;
        int max=(a.get_length()>b.get_length())?a.get_length():b.get_length();
        output.set_length(max);
        Node<int> *p1=a.get_head()->next;
        Node<int> *p2=b.get_head()->next;
        for(int i=2;i<=max;i++){
            if(p1&&p2){
                output.set_value(p1->data+p2->data,i);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1){
                output.set_value(p1->data,i);
                p1=p1->next;
            }
            else if(p2){
                output.set_value(p1->data,i);
                p2=p2->next;
            }
        }
        return output;
    }

    string formal_is(List<int> &a){
        int i=0;
        string outstr;
        Node<int> *p=a.get_head();
        while(p->next){
        p=p->next;
        if(p->data!=0){
            outstr.append(changeToString(p->data)); 
            if(i!=0) {
                outstr.append("x^");
                outstr.append(changeToString(i));
                }
            if(i!=a.get_length()-2) outstr.append(" + ");
        }
        i++;
        }
        return outstr;
    }

    static string changeToString(int value){
        int flag=0;
        if(value<0){
            flag=1;
            value*=-1;
            }
        string str;
        int num=0;
        while(value)
        {
            num=value%10;
            str+=(char)(num+'0');
            value/=10;
        }
        if(flag) str.append("-");
        reverse(str.begin(),str.end());
        return str;
    }
};

void putin(List<int> &a){
    int numIn;
    for(int i=1;i<a.get_length();i++){
        cout<<"第x^"<<i-1<<"项的系数:";
        cin>>numIn;
        a.set_value(numIn,i+1);
    }
}

int main(){
    system("chcp 65001");
    List<int> a;
    List<int> b;
    int along=0;
    int blong=0; 
    cout<<"a多项式最高次"<<endl;
    cin>>along;
    a.set_length(along+2);
    putin(a);
    cout<<"b多项式最高次"<<endl;
    cin>>blong;
    b.set_length(blong+2);
    putin(b);
    formal f;
    List<int> result=f.result(a,b);
    cout<<endl<<"结果是:"<<f.formal_is(result)<<endl;
    system("pause");
}


