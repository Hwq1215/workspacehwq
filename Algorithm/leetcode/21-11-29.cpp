/*https://leetcode-cn.com/problems/k-th-smallest-prime-fraction/      //卡时间没改，看了一个相同思路的
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class mypair{
    public:
    int frist;
    int second;
    double weight;
    mypair(int one,int second){
        this->frist = one;
        this->second = second;
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<mypair> m;
        vector<int> result(2,0);
        int i,j;
        for(i =  0;i<arr.size()-1;i++){
            for(j = i+1;j<arr.size();j++){
                m.push_back(mypair(arr[i],arr[j]));
            }
        }
        if(k >= m.size()/2){
            for(i = 0;i<k;i++){
            for(j = m.size()-1;j>i;j--){
                if(m[j].frist*m[j-1].second>m[j-1].frist*m[j].second){
                    auto x = m[j];
                    m[j] = m[j-1];
                    m[j-1] = x;
                }
            }
        }
        result[0] = m[m.size()-k].frist;
        result[1] = m[m.size()-k].second;
        }else{
            for(i = 0;i<k;i++){
            for(j = m.size()-1;j>i;j--){
                if(m[j].frist*m[j-1].second<m[j-1].frist*m[j].second){
                    auto x = m[j];
                    m[j] = m[j-1];
                    m[j-1] = x;
                }
            }
        }
        result[0] = m[k-1].frist;
        result[1] = m[k-1].second;
        }
        return result;
    }
};

int main(){
    vector<int> t ={1,2,3,5};
    Solution s;
    vector<int> res = s.kthSmallestPrimeFraction(t,3);
    cout<<res[0]<<res[1];
    system("pause");
}