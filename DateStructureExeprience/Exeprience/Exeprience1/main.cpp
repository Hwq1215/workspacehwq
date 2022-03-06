#include<bits/stdc++.h>
#include"Encode.cpp"
using namespace std;

int main(){
    system("chcp 65001");
    string filename="D:\\Temp\\u.bmp";
    //cout<<"请输入文件名";
    //cin>>filename;
    vector<int> weight(256,0);
    FILE *in_file = fopen(filename.c_str(),"rb");
    if(in_file == nullptr){
        cout<<"没有该文件";
        system("pause");
        return 0;
    }
    Encode encode(in_file);
    creatHuffmanFile(encode.coding(),filename);
    printValue(filename);
    fclose(in_file);
system("pause");
return 0;
}