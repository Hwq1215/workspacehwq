#include<iostream>
#include<vector>
using namespace std;

class SortMethod{
    public:
    vector<int> v;
    SortMethod(vector<int> &v){
        this->v = v;
    }
    void doSort(){
        for(int i = 0 ; i<v.size()-1 ; i++){
            for(int j = 0; j<v.size()-i-1 ;j++){
                if(v[j]>v[j+1]){
                    int inst = v[j];
                    v[j] = v[j+1];
                    v[j+1] = inst;
                }
            }
            show();
            cout<<endl;
        }
    }
    private:
    void show(){
        for(int k = 0 ;k < v.size(); k++){
            cout<<v[k]<<" ";
        }
    }
};

int main(){
    int n = 0;
    vector<int> a;
    cout<<"how many nums?"<<endl;
    cin>>n;
    while(n--){
        int in = 0;
        cin>>in; 
        a.push_back(in);
    }
    SortMethod g(a);
    g.doSort();
    system("pause");
}