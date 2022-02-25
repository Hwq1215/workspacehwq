#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if(n==1) return res;
        for(int i = 2;i<=n;i++){
            string ans = "1/";
            char *m;
            sprintf(m,"%d",i);
            ans.append(m);
            res.push_back(ans);
        }
        for(int i = 2;i<n;i++){
            for(int j = i+1;j<=n;j++){
                int k = 0;
                for(k = 2;k<=i;k++){
                    if(i%k==0&&j%k==0) break;
                }
                if(k == i+1){
                    string ans;
                    char *front,*last;
                    sprintf(front,"%d",i);
                    ans.append(front);
                    sprintf(front,"%d",j);
                    ans.push_back('/');
                    ans.append(last);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
    int change_string_int(string s){
        const char *str = s.c_str();
        atoi(str);
    }
};
int main(){

system("pause");
return 0;
}