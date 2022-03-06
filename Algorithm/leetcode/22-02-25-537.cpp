#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string front_1 = num1.substr(0,num1.find('+'));
        string behind_1 = num1.substr(num1.find('+')+1,num1.size()-front_1.size()-2); 
        string front_2 = num2.substr(0,num2.find('+'));
        string behind_2 = num2.substr(num2.find('+')+1,num2.size()-front_2.size()-2);
        int num1_real = change_string_to_int(front_1),
        num2_real = change_string_to_int(front_2),
        num1_vir = change_string_to_int(behind_1),
        num2_vir = change_string_to_int(behind_2);
        int res_real = num1_real*num2_real - num1_vir*num2_vir;
        int res_vir = num1_real*num2_vir + num2_real*num1_vir;
        string res;
        res = change_int_to_string(res_real) + "+" + change_int_to_string(res_vir) + "i";
        return res;
    }
    int change_string_to_int(string s){
        const char *str = s.c_str();
        return atoi(str);
    }
    string change_int_to_string(int n){
        string str = "";
        int flag = 0;
        if(n<0){
            flag = 1;
            n = -n;
        }
        while(n/10){
            str.push_back(n%10 + '0');
            n /= 10;
        }
        str.push_back(n +'0');
        if(flag){ 
            str.push_back('-');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
int main(){
string num1 = "1+4i";
string num2 = "1+-4i";
Solution s;
s.complexNumberMultiply(num1,num2);
system("pause");
return 0;
}