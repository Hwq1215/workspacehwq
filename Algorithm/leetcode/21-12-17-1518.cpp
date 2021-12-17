#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int nullBottles = numBottles;
        int res = numBottles;
        int add = 0;
        while(add = nullBottles/numExchange){
            nullBottles -= add*numExchange - add;
            res += add;
        }
        return res;
    }
};
int main(){
    Solution m;
    printf("%d",m.numWaterBottles(15,4));
    system("pause");
}
