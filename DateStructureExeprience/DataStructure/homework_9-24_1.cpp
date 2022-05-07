//设顺序表Va中的数据元素递增有序，试写一算法，将X插入到顺序表的适当位置上，以保持该表的有序性。
#include<vector>
#include<iostream>
using namespace std;

void insert(vector<int> &a,int x){
    int i=0,j=0;
    int len=a.size();
    if(x>a[len-1]){
        a.push_back(x);
    }
    else{
        for(i=0;i<len;i++){
        if(x<a[i]){
            a.push_back(a[len-1]); //增加位置           
            for(j=len-1;j>i;j--){ 
                a[j]=a[j-1];
            }                      //往后换位，腾出a[i]
            a[i]=x;
            break;
        }
    }
    }
}
int main(){
    vector<int> a={1,2,4,5,6};
    int x=4;
    insert(a,x);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}