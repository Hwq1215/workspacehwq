/*
https://leetcode-cn.com/problems/nth-digit/
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long LL;
class Solution {
public:
    int findNthDigit(int n) {
        int res;
        if(n<10){
            res = n;
        }
        else{
            n = (LL)n;
            LL t = 10,pace = 1,last = 0,num = 1;
            while(n/t){
            last = t;
            pace++;
            t = 9*(LL)pow(10,pace-1)*pace + t;
            }
            num = (LL)pow(10,pace-1) + (n-last)/pace ;
            LL rest = (n - last)%pace;
            int i = pace - rest;
            while(i--){
            res = num%10;
            num = num/10;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout<<s.findNthDigit(189)<<endl;
    system("pause");
}