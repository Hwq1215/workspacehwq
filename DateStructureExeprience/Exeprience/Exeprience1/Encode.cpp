#include<bits/stdc++.h>
#include"Huffman.cpp"
#include"Compression.cpp"
using namespace std;

class Encode{
    private:
    int nSize;
    FILE *p;
    string outPut; 
    vector<HuffmanTree> hufTree;
    vector<string> hufCode;
    vector<int> weight;

    public:
    Encode(FILE *in_file){
        this->p = in_file;
        int c;
        weight.resize(256,0);
        while((c = fgetc(in_file)) != EOF){
            //printf("%02X ",c);
            weight[c]++;
        }
        hufTree = createHuffmanTree(weight);
        PrintHuffman();
        hufCode = HuffmanCoding(hufTree); 
    }

    string coding(){
        string buf;
        int c;
        rewind(p);
        while((c = fgetc(p)) != EOF){
            buf.append(hufCode[c]);
        }
        int index = 0;
        nSize = buf.size()/8 + (buf.size()%8==0? 0:1);
        cout<<buf<<endl;
        for(int i = 0;i<nSize;i++){
            while(index<=buf.size()){
            outPut.push_back(Str2byte(buf.substr(index,index+8)));
                index += 8;
            }
        }
        cout<<"str1:"<<endl<<buf.size()<<endl;
        fclose(p);
        return outPut;
    }
    
    vector<int> getWeight(){
        return weight;
    }

    void PrintHuffman(){
        cout<<"order"<<"    lchild"<<"    parent"<<"    rchild"<<"    weight"<<endl;
        for(int i = 1;i<512;i++){
            printf("%5d",i);
            printf("%10d",hufTree[i].lchild);
            printf("%10d",hufTree[i].parent);
            printf("%10d",hufTree[i].rchild);
            printf("%10d",hufTree[i].weight);
            cout<<endl;
        }
    }

};

