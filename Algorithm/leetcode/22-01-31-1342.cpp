#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0,cnt = 0;
        if(num == 0) return 0;
        while(num != 0){
            if(num%2){
                res += 1;
            } 
            cnt++;
            num = num>>1;
        }
        res = res + cnt - 1;
        return res;
    }
};
int main(){

system("pause");
return 0;
}