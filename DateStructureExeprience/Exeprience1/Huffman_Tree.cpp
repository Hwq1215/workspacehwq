#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;
template<class element>
class HuffmanTree{
    public:
    element weight;
    int parent,lchild,rchild;
};

template<class element>
class HuffmanCode{
    private:
    vector<HuffmanTree<element>> Htree;
    int m,n;
    vector<string> code;
    public:
    HuffmanCode(vector<element> into){
        n=into.size();
        m=2*n-1;
        Htree.resize(m+1);
        for(int i=1;i<=m;i++){
            if(i<=n) Htree[i].weight=into[i-1];
            Htree[i].lchild=0;
            Htree[i].rchild=0;
            Htree[i].parent=0;
        }
    make();                 //生成Huffman树
    coding();               //进行编码
    }

    void show(){
        for(int i=0;i<code.size();i++){
            cout<<Htree[i+1].weight<<":"<<code[i]<<endl;
        }
    }

    private:
    void make(){
        int minest,miner;
        for(int i=n+1;i<=m;i++){
            selete(Htree,i-1,minest,miner); //挑选最小的两个结点
            Htree[i].weight=Htree[minest].weight+Htree[miner].weight;
            Htree[i].lchild=minest;
            Htree[i].rchild=miner;
            Htree[minest].parent=i;
            Htree[miner].parent=i;
        }
    }   
    void selete(vector<HuffmanTree<element>> t,int k,int &minest,int &miner){
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
    h.show();
    system("pause");
}
