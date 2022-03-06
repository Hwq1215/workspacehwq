#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
#include <io.h> 
#include <sys\stat.h> 
using namespace std;

struct HEAD{
    string type;
    int length;
    int weight[256];
};
char Str2byte(string s){
    char b = 0x00;
    for(int i = 0;i<8;i++){
        b=b<<1;
        if(s[i]=='1'){
            b = b|0x01;
        }
    }
    return b;
}

void creatHuffmanFile(string result,string filename){
    string newFilename = filename+".huf";
    ofstream ofile(newFilename,ios::binary);
    ofile<<result;
    ofile.close();
}

void printValue(string filename){
    string newFilename = filename+".huf";
    long newSize = 0;
    long oldSize = 0;
    FILE *oldfile = fopen(filename.c_str(), "rb"); 
    if (oldfile) 
    { 
    oldSize = filelength(fileno(oldfile));
    }
    FILE *newfile = fopen(newFilename.c_str(),"rb"); 
    if (newfile) 
    { 
    newSize = filelength(fileno(newfile));
    }
    cout<<"----压缩完成----"<<endl;
    cout<<"原来文件大小："<<oldSize<<"B"<<endl;
    cout<<"新文件文件大小："<<newSize<<"B"<<endl;
    cout<<"压缩率是"<<newSize*1.0/oldSize<<endl;
}
