#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

int main(){
    vector<int> person;
    vector<int> times;
    TopVotedCandidate* obj = new TopVotedCandidate(person,times);
    system("pause");
}

class TopVotedCandidate {
public:
    int *winner;
    int maxtime;
    int lastSelection;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        maxtime = times[times.size()-1];
        int i = 0,p = 0;
        int selectMAX = 0;
        map<int,int> selector;
        winner = new int[times[times.size()-1]+1];
        for(p = 0;p<persons.size()-1;p++){
            selector[persons[p]]++;
            if(selectMAX <= selector[persons[p]]){
                for(i = times[p];i<times[p+1];i++){
                    winner[i] = persons[p];
                }
                selectMAX = selector[persons[p]];
            }
            else{
                for(i = times[p];i<times[p+1];i++){
                    winner[i] = winner[i-1];
                }
            }
        }
        selector[persons[p]]++;
        if(selectMAX <= selector[persons[p]]){
            winner[i] = persons[p];
        }
        else{
            winner[i] = winner[i-1];
        }
        lastSelection = winner[i];
    }
    
    int q(int t) {
        if(t>=maxtime){
            return lastSelection;
        }
        return winner[t];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */