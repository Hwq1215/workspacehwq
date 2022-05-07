#include<bits/stdc++.h>
using namespace std;

bool is_prime(int num){
    if(num==2||num==3){
        return true;
    }else if(num%6!=1&&num%6!=5){
        return false;
    }else{
        int tem = sqrt(num);
        for(int val = 5;val<=tem;val+=6){
            if(num%val==0||num%(val+2)==0){
                return false;
            }
        }
    }
    return true;
}

int add_all_num(int num){
    int res = 0;
    while(num){
        res += num%10;
        num /= 10;
    }
    return res;
}

int main(){ 
    int inp = 1;
    do{
        scanf("%d",&inp);
        if(inp == 0) return 0;
        int index = inp;
        int res1 = 1,res2 = 0;
        while(res1!=res2){
            index++;
            int ins = index;
            res2 = 0;
            res1 = add_all_num(ins);
            while(!is_prime(ins)&&ins!=1){
                int temp = sqrt(ins);
                for(int i = 2;i<=temp+1;i++){
                    if(ins%i == 0){
                        res2 += add_all_num(i);
                        ins /= i;
                        break;
                    }
                }
            }
            res2 += add_all_num(ins);
        }
        cout<<index<<endl;
    }while(inp!=0);

system("pause");
return 0;
}

