#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
typedef long long ll;
using namespace std;

ll findValue(int l, int r, ll tag, vector<ll> array);
int main(){
    int n = 0;
    cin >> n;
    ll total = 0;
    ll coins = 0;
    vector<ll> heros(n);
    for(int i = 0; i<n ;i++){
        cin >> heros[i];
        total += heros[i];
    }
    sort(heros.begin(),heros.end());
    ll min = heros[0];
    ll max = heros[heros.size()-1];
    cin >> n;
    for(int i = 0; i<n ;i++){
        ll heroPart = 0,restPart = 0;
        ll defence,power;
        cin>>defence;
        cin>>power;
        if(defence <= min){
            if(power > total - min){
                restPart = power - (total - min);
            }
        }
        else if(defence >= max){
            heroPart = defence - max;
            if(power > total - max){
                restPart = power - (total - max);
            }
        }
        else{
            ll warer = findValue(0,heros.size()-1,defence,heros);
            heroPart = defence - warer;
            if(power > total - warer){
                restPart = power - (total - warer);
            }
        }
        cout<<(ll)(heroPart + restPart)<<endl;
    }
}

ll findValue(int l, int r, ll tag, vector<ll> array){
    int res = 0;
    int mid = (l+r)>>1;
    while(l <= r){
        if(tag > array[mid]){
            l = mid +1;
            mid = (l+r)>>1; 
        }else if(tag < array[mid]){
            r = mid -1;
            mid = (l+r)>>1;
        }
        else{
            res = mid;
            break;
        }
        if(abs(array[res]-tag)>abs(array[mid]-tag)) res = mid;
    }
    return array[res];
}