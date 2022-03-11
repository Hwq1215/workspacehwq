#include<bits/stdc++.h>
#include<fstream>
#include"HuffmanTree.hpp"
#include<windows.h>
using namespace std;

class OnCode{
    private:
    string str;
    public:
    
    OnCode(const char* in_file_path,const char* out_file_path,vector<int> weight){
        FILE *out_file = fopen(out_file_path,"wb");
        FILE *in_file = fopen(in_file_path,"rb");
        if(out_file == nullptr){
            cout<<"找不到输出文件";
        }
        if(in_file == nullptr){
        cout<<"没有该文件";
        }else{
            /*
            vector<int> weight(256,0);
            for(int pos = 0; (!feof(in_file)) && pos<256;pos++){
                char ch = fgetc(in_file);
                weight[pos] = ch;
            }
            */
            vector<HuffmanTree> hufTree = createHuffmanTree(weight);
            char c;
            while(!feof(in_file)){
                c = fgetc(in_file);
                str.append(char_Byte(c));
            }
            cout<<"str2:"<<endl<<str.size()<<endl;
            int index = 511;
            long long i = 0;
            for(;i<str.size();i++){
                if(hufTree[index].lchild != 0 || hufTree[index].rchild != 0){
                    if(str[i] == '0'){
                        index = hufTree[index].lchild;
                    }else{
                        index = hufTree[index].rchild;
                    }
                }else{
                    i--;
                    index--;
                    //printf("%02X ",index);
                    fputc((char&)index,out_file);
                    index = 511;
                }
            }
        }
        fclose(out_file);
        fclose(in_file);
    }
    
    bool onFile(const std::string &src, const std::string &dest){
    Sleep(2000);
    std::ifstream fin(src.c_str(), std::ios::in | std::ios::binary);
    if(!fin)
    {
        std::cout << "open in file[" << src << "] failed" << std::endl;
        return false;
    }
    std::ofstream fout(dest.c_str(), std::ios::out | std::ios::binary);
    if(!fout)
    {
        std::cout << "open out file[" << dest << "] failed" << std::endl;
        return false;
    }
    fout << fin.rdbuf();
    return true;
}
};