#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        int index = 0,has_right = 0,i = 0;
        for(i = 0;i<dominoes.size();i++){
            //往右倒的
            if(dominoes[i]=='R'){
                if(has_right){
                    dominoes.replace(dominoes.begin()+index,dominoes.begin()+i,i-index,'R');
                }
                has_right = 1;
                index = i+1; 
            //往左倒的
            }else if(dominoes[i]=='L'){
                if(has_right){
                    if(i-index>1){
                    dominoes.replace(dominoes.begin()+index,dominoes.begin()+(i+index)/2,(i-index)/2,'R');
                    dominoes.replace(dominoes.begin()+(i+index+1)/2,dominoes.begin()+i,(i-index)/2,'L');
                    }
                }else{
                    dominoes.replace(dominoes.begin()+index,dominoes.begin()+i,i-index,'L');
                }
                index = i+1;
                has_right = 0;
            }
        }
        //最后往右倒的
        if(dominoes[i-1]!='L'&&has_right){
            dominoes.replace(dominoes.begin()+index,dominoes.end(),i-index,'R');
        }
        return dominoes;
    }
};
int main(){
    
system("pause");
return 0;
}
