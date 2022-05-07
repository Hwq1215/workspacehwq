#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string copy_a = a;
        int length = a.size();
        int res = -1;
        int cnt = 1;
        do{ 
            if(a.size() < b.size()){
                a.append(copy_a);
                cnt++;
            }else{
                if(a.find(b) != a.npos){
                res = cnt;
                return res;
                }
                a.append(copy_a);
                cnt++;
                if(a.find(b) != a.npos){
                res = cnt;
                return res;
                }
            }
        }while(a.size() <= b.size() + 2 * (length-1));
        return res;
    }
};
int main(){
    Solution a;
    cout<<a.repeatedStringMatch("abc","cabcabca");
    system("pause");
}
