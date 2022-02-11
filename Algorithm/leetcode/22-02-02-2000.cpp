#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = word.find_first_of(ch);
        if(i != word.npos) reverse(word.begin(),word.begin()+i);
        return word;
    }   
};
int main(){
    string m ="abcdefgh";
reverse(m.begin(),m.begin()+2);
cout<<m;
system("pause");
return 0;
}