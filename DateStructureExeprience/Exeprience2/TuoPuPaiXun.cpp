#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private: 
        int term;
        int total;
        vector<pair<string,int>> subject;
        vector<vector<int>> connection;
    public:
        Graph(int total){
            vector<vector<int>> rec(total,vector<int>(total,0));
            connection = rec;
            this->total = total;
            int i = 0;
            cout<<"give the subjects' code and credit(using string):"<<endl;
            while(i++<total){
                int credit;
                string str;     
                cin>>str;
                cin>>credit;
                subject.push_back(pair<string,int>(str,credit));
            }
            for(i = 0;i<total;i++){
                int cnt = 0;
                cout<<"if "<<subject[i].first<<" connect to some subject?"<<endl
                <<"if is,give numbers of the subject connnected to"<<endl
                <<"if isn't,just key 0"<<endl;
                cin>>cnt;
                while(cnt--){
                    string str;
                    cout<<"which one is it connected ?   ";
                    cin>>str;
                    for(int j = 0;j<total;j++){
                        if(str == subject[j].first){
                            connection[i][j] = 1;
                        }
                    }
                }
            }
        }
};

int main(){
    Graph g(5);
}