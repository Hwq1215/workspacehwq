#ifndef EE7132C7_94F7_49ED_A599_6D6E829DFDCC
#define EE7132C7_94F7_49ED_A599_6D6E829DFDCC
#include<bits/stdc++.h>
using namespace std;

class Place{
    public:
    std::string name;
    std::string introduce;

    Place(){};

    Place(string name,string introduce){
        this->name = name;
        this->introduce = introduce;
    }
    ~Place(){};
};

#endif /* EE7132C7_94F7_49ED_A599_6D6E829DFDCC */
