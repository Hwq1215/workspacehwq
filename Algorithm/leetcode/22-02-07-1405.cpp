#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        if(a==0&&b==0&&c==0) return "";
        char ch_max,ch_se,ch_th;
        int index = 0,jump = 2,num_max = 0,num_se,num_th;
        if(a>=b&&a>=c){
            ch_max = 'a',ch_se = 'b',ch_th = 'c';
            num_max = min(a,(b+c+1)*2),num_se = b ,num_th = c;
        }else if(b>c&&b>a){
            ch_max = 'b',ch_se = 'a',ch_th = 'c';
            num_max = min(b,(a+c+1)*2),num_se = a ,num_th = c;
        }else{
            ch_max = 'c',ch_se = 'b',ch_th = 'a';
            num_max = min(c,(b+a+1)*2),num_se = b ,num_th = a;
        }
            res.append(string(num_max,ch_max));
            while(num_se){
                if(jump == 2){
                    index += 2;
                    if(index>=res.size()){
                        index = 0;
                        jump = 1;
                        continue;
                    }
                    res.insert(res.begin()+index,ch_se);
                    num_se--;
                    index++;
                }else if(jump == 1){
                    index++;
                    if(index<res.size()){
                        if(res[index-1]!=ch_se&&res[index]!=ch_se){
                            res.insert(res.begin()+index,ch_se);
                            index++;
                            num_se--;
                        }
                    }else{
                            res.push_back(ch_se);
                            num_se--;
                    }
                }
            }
            while(num_th){
                if(jump == 2){
                    index += 2;
                    if(index>=res.size()){
                        index = 0;
                        jump = 1;
                        continue;
                    }
                    res.insert(res.begin()+index,ch_th);
                    num_th--;
                    index++;
                }else if(jump == 1){
                    index++;
                    if(index<res.size()){
                        if(res[index-1]!=ch_th&&res[index]!=ch_th){
                            res.insert(res.begin()+index,ch_th);
                            index++;
                            num_th--;
                        }
                    }else{
                            res.push_back(ch_th);
                            num_th--;
                            index = 0;
                    }
                }
            }
       
        return res;
    }
};
int main(){
    Solution s;
    string res =s.longestDiverseString(15,15,3); 
cout<<res;
system("pause");
return 0;
}