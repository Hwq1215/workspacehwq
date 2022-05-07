//试写一算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表（a1,a2,a3,…….an）逆置为（an,an-1…….a1)。
#include<vector>
#include<iostream>
using namespace std;

int reback(vector<int>&a){
    int i=0,t=0;
    for(i=0;i<a.size()/2;i++){
        t=a[i];
        a[i]=a[a.size()-1-i];
        a[a.size()-1-i]=t;
    }
}
int main(){
    vector<int> a={1,2,4,5,6};
    reback(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}
