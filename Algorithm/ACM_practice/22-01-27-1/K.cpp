#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime_3( ll num )
{
                 //两个较小数另外处理
                 if(num ==2|| num==3 )
                                 return 1 ;
                 //不在6的倍数两侧的一定不是质数
                 if(num %6!= 1&&num %6!= 5)
                                 return 0 ;
                 ll tmp =sqrt( num);
                 //在6的倍数两侧的也可能不是质数
                 for(ll i= 5;i <=tmp; i+=6 )
                                 if(num %i== 0||num %(i+ 2)==0 )
                                                 return 0 ;
                 //排除所有，剩余的是质数
                 return 1 ;

}
int main(){
ll nav;
cin>>nav;
int pos = (int)log10(nav)+1;
ll div = pow(10,pos-1);
ll ins = nav;
ll add_num = 0;
while(ins>10){
    add_num *= 10;
    ins /= 10;
    ll num = ins % 10;
    add_num += num;
}
    nav = nav*div+add_num;
    if(isPrime_3(nav)){
        cout<<"prime"<<endl;
    }else{
        cout<<"noprime"<<endl;
    }
    
system("pause");
return 0;
}