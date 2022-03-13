#ifndef A12FA39B_3AEE_4BA7_898F_A433CD1A4C9B
#define A12FA39B_3AEE_4BA7_898F_A433CD1A4C9B
#include<bits/stdc++.h>
using namespace std;

class Road{
    public:
    std::string first;
    std::string second;
    int length;
    
    Road(){};

    Road(string first,string second,int length){
        this->first = first;
        this->second = second;
        this->length = length;
    }
    ~Road(){};
};

#endif /* A12FA39B_3AEE_4BA7_898F_A433CD1A4C9B */
