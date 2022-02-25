#include<bits/stdc++.h>
using namespace std;
/*
本身是质数1，2，3，5，7，11，13，17，19，23，29
6：2*3
10：2*5
14：2*7
15：3*5；
21：3*7
22：2*11
26：2*13
30：2*3*5
*/
class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int res = 0,res_frist = 0;
        int is_unable_num = 0;
        unordered_map<int,int> mymap,m;
        for(auto num:nums){
            mymap[num]++;
        }
        for(int i = 2;i<=30;i++){
            if(mymap.count(i)&&is_unnum(i)) {
                if(i<14){
                    m[i]++;
                }
                is_unable_num++;
            }
        }
        res_frist = (is_unable_num + 1)*is_unable_num/2;
        //6
        int res_6 = mymap[6]*(is_unable_num-m[2]-m[3]+1) * (is_unable_num-m[2]-m[3]) /2;
        //10
        int res_10 = mymap[10]*(is_unable_num-m[2]-m[5]+1) * (is_unable_num-m[2]-m[5]) /2;
    }
    bool is_unnum(int n){
        if(n==2||n==3||n==5){
            return true;
        }else if(n%6!=1||n%6!=5){
            return true;
        }else{
            int tmp =sqrt(n);
            for(int i= 5;i <=tmp; i+=6 )
                if(n %i== 0||n %(i+ 2)==0 )
                    return false ;
        }
        return true;
    }
};
int main(){

system("pause");
return 0;
}