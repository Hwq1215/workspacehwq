#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = 0,max;
        max = min(rectangles[0][0],rectangles[0][1]);
        for(vector<int> val:rectangles){
            int m = min(val[0],val[1]);
            if( m > max){
                max = m;
                res = 1;
            }else if(m == max){
                res++;
            }
        }
        return res;
    }
};
int main(){

system("pause");
return 0;
}
