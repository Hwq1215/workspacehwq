#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int k,n;
    cin>>k;
    cin>>n;
    double result = sqrt(k*k+n*k);
    int i=1,j;
    double front;
    if(n==0){
        result = k;
        cout<<k;
    }
    else{
        do{
         front = result;
        result = sqrt(k*k+(n+i*k)*k);
        for(j = i-1;j!=-1;j--){
            result = sqrt(k*k+(n+j*k)*result);
        }
        i++;
        }while(result-front>0.01);
        cout<<int(result+1);
    }
    system("pause");
}