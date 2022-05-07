#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int size = arr.size();
        int maxVal = 0,index;
        while(size != 1){
            maxVal = 0;
            for(int i = 0;i<size;i++){
                if(maxVal<arr[i]){
                    index = i;
                    maxVal = arr[i];
                }  
            }
            if(index == size-1){
            }else if(index==0){
                res.push_back(size);
                reverse(arr.begin(),arr.begin()+size);
            }else{
                res.push_back(index+1);
                reverse(arr.begin(),arr.begin()+index+1);
                res.push_back(size);
                reverse(arr.begin(),arr.begin()+size);
            }
            size--;
        }
    return res;
    }
};
int main(){
Solution s;
vector<int> v={3,2,4,1};
s.pancakeSort(v);
system("pause");
return 0;
}