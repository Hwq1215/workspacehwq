#include<bits/stdc++.h>
#include"HuffmanTree.hpp"
using namespace std;

vector<HuffmanTree> createHuffmanTree(vector<int> in){
    vector<HuffmanTree> result(513);
    result[0].weight = INT32_MAX;
    for(int i = 0;i<256;i++){
        result[i+1].weight = in[i]; 
    }
    for(int i = 257;i<513;i++){
        int miner = 0,minest = 0;
        if(select(i,miner,minest,result)){
            result[i].lchild = minest;
            result[i].rchild = miner;
            result[i].weight = result[miner].weight + result[minest].weight;
            result[miner].parent = i;
            result[minest].parent = i;
        }
    }
    return result;
}

vector<string> HuffmanCoding(vector<HuffmanTree> res){
    vector<string> huffmanCode(256);
    for(int i = 0;i<256;i++){
        int index = i+1;
        HuffmanTree h = res[index];
        if(h.weight==0){
            continue;
        }
        string code = "";
        while(h.parent != 0){
            if(index==res[h.parent].lchild){
                code.push_back('0');
            }else if(index==res[h.parent].rchild){
                code.push_back('1');
            }
            index = h.parent;
            h = res[h.parent];
        }
        reverse(code.begin(),code.end());
        huffmanCode[i] =  code;
    }
    return huffmanCode;
}

bool select(int pos,int & miner,int & minest,vector<HuffmanTree> & t){
    miner = 0,minest = 0;
    for(int i = 1;i<pos;i++){
        if(t[i].parent == 0 && t[i].weight<=t[minest].weight){
            miner = minest;
            minest = i;
        }else if(t[i].parent == 0 && t[i].weight<=t[miner].weight){
            miner = i;
        }
    }
    if(miner == 0 || minest == 0 ) return false;
    return true;
}

void testHuffman(vector<int> in){
    vector<HuffmanTree> re = createHuffmanTree(in);
    for(int i = 0;i<re.size();i++){
        cout<<i<<":"<<re[i].weight<<endl;
    }
    vector<string> outp = HuffmanCoding(re);
    for(int i = 0;i<outp.size();i++){
        cout<<i+1<<":"<<outp[i]<<endl;
    }
}


