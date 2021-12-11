#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int x,y;
    for(x = 1;(x*(x+1))/2<n;x++){
        for(y = x;(y*(y+1))/2<n;y++){
            if((x*x + y*y + x + y)/2 == n){
                cout<<"YES";
                return 0;
            }
        }
    }    
    cout<<"NO";
    return 0;
}