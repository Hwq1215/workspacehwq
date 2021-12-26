#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int dayOfYear(string date) {
        int res = 0;
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + date[3] - '0'; 
        int month = (date[5]-'0')*10 + (date[6]-'0');
        int day = (date[9]-'0')*10 + date[10]-'0';
        switch (month)
        {
        case 12:
            res += 30;
        case 11:
            res += 31;
        case 10:
            res += 30;
        case 9:
            res += 31;
        case 8:
            res += 31;
        case 7:
            res += 30;
        case 6:
            res += 31;
        case 5:
            res += 30;
        case 4:
            res += 31;
        case 3:
            res += is_runYear(year)? 29:28;
        case 2:
            res += 31;
        case 1:
            res += day;
            break;
        default:
            break;
        }
        return res;
    }

    bool is_runYear(int year){
        if((!(year%4) && year%100)||(!(year%100) && !(year%400))){
            return true;
        }
        return false;
    }
};
int main(){
    Solution a;
    cout<<a.is_runYear(2000);
    system("pause");
}