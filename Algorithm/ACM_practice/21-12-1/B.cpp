#include<iostream>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
    int length,n;
    scanf("%d%d",&length,&n);
    string dna[n],str;
    int A = 0,C = 0,G = 0,T = 0;
    int cnt[n];
    int cal = 0;
    for(int i = 0 ;i<n; i++){
        cin>>str;
        dna[i] = str;
        for(int j = 0 ;j<length; j++){
            switch(str[j]){
                case 'A':
                    cal += C + G + T;
                    break;
                case 'C':
                    C++;
                    cal += G + T;
                    break;
                case 'G':
                    G++;
                    cal += T;
                    break;
                case 'T':
                    T++;
                    break;
            }
        } 
        cnt[i] = cal;
        A = C = G = T = cal = 0;
    }
    for(int i = 0;i<n-1;i++){
        for(int j = n-1 ; j>i ;j--){
            if(cnt[j] < cnt[j-1]){
                auto temp = cnt[j];
                cnt[j] = cnt[j-1];
                cnt[j-1] = temp;
                auto str_temp = dna[j];
                dna[j] = dna[j-1];
                dna[j-1] = str_temp;
            } 
        }
        cout<<dna[i]<<endl;
    }
    cout<<dna[n-1];
}