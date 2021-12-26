#include<iostream>
#include<vector>
using namespace std;

class Subject{
    public:
    int rudes;
    int order;
    int credit;
    vector<int> preSubject;
    string name;
    Subject(){};
    Subject(int order,int credit,string name){
        this->order = order;
        this->credit = credit;
        this->name =name;
        };
    void put_back(int _order){
        preSubject.push_back(_order);
    }
};

class Graph{
    private: 
        int terms;
        int total;
        int MaxCredit;
        int TotalCredit = 0;
        vector<Subject> subject;
        vector<Subject> result;
        vector<vector<Subject>> TermSubject;
    public:
        Graph(){
            cout<<"how many terms"<<endl;
            cin>>terms;
            TermSubject.resize(terms);
            cout<<"hou large does one term's credit has"<<endl;
            cin>>MaxCredit; 
            cout<<"how many subjects you want?"<<endl;
            cin>>total;
            this->total = total;
            int i = 0;
            cout<<"give the subjects' code and credit(using string):"<<endl;
            while(i++<total){
                int credit;
                string str;     
                cin>>str;
                cin>>credit; 
                TotalCredit =+ credit;
                subject.push_back(Subject(i,credit,str));
            }
            for(i = 0;i<total;i++){
                int cnt = 0;
                cout<<"if "<<subject[i].name<<" connect to some subject?"<<endl
                <<"if is,give numbers of the subject before"<<endl
                <<"if isn't,just key 0"<<endl;
                cin>>cnt;
                subject[i].rudes = cnt;
                while(cnt--){
                    string str;
                    cout<<"which one is it connected ?";
                    cin>>str;
                    for(int j = 0;j<total;j++){
                        if(str == subject[j].name){
                            subject[j].put_back(subject[i].order);
                        }
                    }
                }
            }
        }
        void TuoPusort(){
            int cnt = 0;
            int terms_cnt = 0;
            while(subject.size() != 0 ){ 
                vector<int> mark;
                for(int i = 0;i<subject.size();i++){
                    if(subject[i].rudes == 0){
                        mark.push_back(i);
                    }
                }
                selectMin(mark);
                mark.clear();
                if(put_in_term(cnt,terms_cnt,result,TermSubject) == false) return;
            }
        }
        void showResult(){
            for(int i=0 ;i<result.size(); i++){
                cout<<result[i].name<<" ";
            }
            cout<<endl;
            for(int i = 0;i<TermSubject.size();i++){
                cout<< i+1 <<"term: ";
                for(int j = 0;j<TermSubject[i].size();j++){
                     cout<<TermSubject[i][j].name<<" ";
                }
                cout<<endl;
            }
            if(divide_adverage() == true){
            for(int i = 0;i<TermSubject.size();i++){
                cout<< i+1 <<"term: ";
                for(int j = 0;j<TermSubject[i].size();j++){
                     cout<<TermSubject[i][j].name<<" ";
                }
                cout<<endl;
            }
            }else{
                cout<<"has the max Terms";
            }
            
        }
        private:
        void selectMin(vector<int> &mark){
            for(int m = 0;m<mark.size();m++){
                for(int j = 0;j<subject[mark[m]].preSubject.size();j++){
                            for(int k = 0;k<subject.size();k++){
                                if(subject[k].order == subject[mark[m]].preSubject[j]){
                                    subject[k].rudes--;
                                }
                            }
                        }
                        result.push_back(subject[mark[m]]);
            }
            for(int m = 0;m<mark.size();m++){
                subject.erase(subject.begin()+mark[m] - m);
            }
        }
        bool put_in_term(int &cnt,int &terms_cnt,vector<Subject> &v,vector<vector<Subject>> &t){
            if(cnt>=v.size()||terms_cnt>=t.size()) return false;
            int sum = 0;
            for(;cnt<v.size();cnt++){
                if(sum + v[cnt].credit <= MaxCredit){
                    sum += v[cnt].credit;
                    t[terms_cnt].push_back(v[cnt]);
                }
                else{
                    if(sum == 0) return false;
                    else{
                        terms_cnt++;
                        sum = 0;
                        if(sum + v[cnt].credit <= MaxCredit){
                        sum += v[cnt].credit;
                        t[terms_cnt].push_back(v[cnt]);
                    }
                        if(terms_cnt == t.size()) return false;
                    }
                }
            }
            terms_cnt ++;
            return true;
        }
        bool divide_adverage(){
            if(if_has_empty_term()&&!is_everyone_one()){
                int biggest_one = search_biggest_term();
                int divide_num = TermSubject[biggest_one].size();
                int i =TermSubject.size()-2;
                for(i = TermSubject.size()-2;i>biggest_one;i--){
                    TermSubject[i+1] = TermSubject[i];
                }
                if( TermSubject.size())TermSubject[i+1].erase(TermSubject[i+1].begin(),TermSubject[i+1].end());
                for(int j = divide_num/2-1;j<TermSubject[i].size();j++){
                    TermSubject[i+1].push_back(TermSubject[i].back());
                    TermSubject[i].pop_back();
                }
                divide_adverage();
            }
            else return false;
            return true;
        }
        bool if_has_empty_term(){
            for(int i = 0;i<TermSubject.size();i++){
                if(TermSubject[i].size() == 0){
                    return true;
                }
            }
            return false;
        }
        bool is_everyone_one(){
            for(int i = 0;i<TermSubject.size();i++){
                if(TermSubject[i].size() != 1){
                    return false;
                }
            }
            return true;
        }
        int search_biggest_term(){
            int biggest_one = 0;
            int big_value = TermSubject[0].size();
            for(int i = 0;i<TermSubject.size();i++){
                biggest_one =  TermSubject[i].size() > big_value? i:biggest_one; 
            }
            return biggest_one;
        }
};

int main(){
    Graph g;
    g.TuoPusort();
    g.showResult();
    system("pause");
}