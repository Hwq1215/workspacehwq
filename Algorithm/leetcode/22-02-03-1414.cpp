#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a{1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,
    10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,
    3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,
    267914296,433494437,701408733,1134903170};
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int res = 0;
        ll last = 1,rest = k;
        while( rest>0 ){
            for(ll val : a){
                if(rest<val){
                    rest = rest - last;
                    res++;
                    break;
                } 
                else if(rest == val){
                    res++;
                    rest = 0;
                    break;
                } 
                else{
                last = val;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.findMinFibonacciNumbers(19);
system("pause");
return 0;
}