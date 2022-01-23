#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int i = 1,mark = 0,max = releaseTimes[0];
        while(i<keysPressed.size()){
            int val = releaseTimes[i]-releaseTimes[i-1];
            if(val > max){
                max = val;
                mark = i;
            }else if(val == max && keysPressed[i] > keysPressed[mark]){
                max = val;
                mark = i;
            }
            i++;
        }
        return keysPressed[mark];
    }
};

int main(){

system("pause");
return 0;
}
