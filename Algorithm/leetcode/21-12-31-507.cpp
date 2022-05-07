#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sum = 1;
        vector<int> nums;
        for(int i = 2;num>=i*i;i++){
           if(!(num%i)){
               sum += i;
               sum +=(num/i);
           }
        }
        if(sum == num) return true;
        return false;
    }
};

int main(){
Solution a;
cout<<a.checkPerfectNumber(28);
system("pause");
return 0;
}

