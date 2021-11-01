#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;

class HuffmanTree{
    public:
    double weight;
    int parent,lchild,rchild;
};

template<class element>
class HuffmanCode{
    private:
    vector<HuffmanTree> Htree;
    int n;
    vector<string> code;

HuffmanCode(vector<element> into){
    n=into.size();
    int m=2*n-1;
    Htree.resize(m+1);
    for(int i=1;i<=m;i++){
         if(i<=n) Htree[i].weight=into[i-1];
         Htree[i].lchild=0;
         Htree[i].rchild=0;
         Htree[i].parent=0;
    }

}
    public:
    void make(){
        int minest,miner;
        for(int i=n+1;i<=m;i++){
            selete(Htree,i-1,minest,miner);
            Htree[i].weight=Htree[minest].weight+Htree[miner].weight;
            Htree[i].lchild=minest;
            Htree[i].rchild=miner;
            Htree[minest].parent=i;
            Htree[miner].parent=i;
        }
        coding();
    }

    int show(){
        for(int i=0;i<code.size();i++){
            cout<<Htree[i+1].weight<<":"<<code[i]<<endl;
        }
    }
        
    private:
    void selete(vector<HuffmanTree> t,int k,int &minest,int &miner){
        int cnt=0;
        miner=0;
        minest=0;
        for(int i=1;i<=k;i++){
            cnt=0;
            if(t[i].parent!=0) continue;
            for(int j=1;j<=k;j++){
                if(t[j].parent!=0) continue;
                if(t[i].weight>t[j].weight){
                    cnt++;
                }
            }
            if(cnt==0&&!minest) {
                minest=i;
                }
            else if(cnt==0){
                miner=i;
            }
            if(cnt==1) miner=i;
        }
    }

    void coding(){
            string str;
            for(int i=1;i<=n;i++){
                for(int h=i;Htree[h].parent!=0;h=Htree[h].parent){
                    if(h==Htree[Htree[h].parent].lchild){
                        str.append("0");
                    }
                    else if(h==Htree[Htree[h].parent].rchild){
                        str.append("1");
                    }
                }
                reverse(str.begin(),str.end());
                code.push_back(str);
                str.clear();
            }
        }
};




int main(){
    int total;
    double dol;
    cout<<"how many codes you need:";
    cin>>total;
    vector<double> input;
    cout<<"Huffman_number:";
    for(int i=0;i<total;i++){
        cin>>dol;
        input.push_back(dol);
    }
    HuffmanCode<double> h(input);
    h.make();
    h.show();
    system("pause");

}
