#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double quickMul(double x,long long N){
        double res = x,ans = 1.0;
        while( N > 0){
            ans = res * (N%2);
            res = res * res;
            N >>= 1;
        }
        return ans;
    }
    
    double myPow(double x, int n) {
        long long N = n;
        return n>0? quickMul(x,N):1.0/quickMul(x,-N);
    }
};
int main(){
    Solution s;
cout<<s.myPow(4.0,-1);
system("pause");
return 0;
}