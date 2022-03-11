#include<bits/stdc++.h>
#include"Encode.cpp"
#include"OnCoding.cpp"
#include<windows.h>
using namespace std;

int main(){
    system("chcp 65001");
    string filename="D:\\Temp\\pic.bmp";
    //cout<<"请输入文件名";
    //cin>>filename;
    FILE *in_file = fopen(filename.c_str(),"rb");
    if(in_file == nullptr){
        cout<<"没有该文件";
        system("pause");
        return 0;
    }
    Encode encode(in_file);
    creatHuffmanFile(encode.coding(),filename,encode.getWeight());
    printValue(filename);
    fclose(in_file);
    cout<<"解压中~~~"<<endl;
    OnCode oncode("D:\\Temp\\pic.bmp.huf","D:\\Temp\\picNew.bmp",encode.getWeight());
    cout<<"解压完成"<<endl;
system("pause");
return 0;
}