#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int q = 0;
    cin>>q;
    for(int i = 0;i<q;i++){
        long long sum = 0;
        int front;
        int length;
        cin>>front>>length;
        for(int j = 0;j<length;j++){
            sum += a[front-1];
            front++;
        }
        cout<<sum<<endl;
    }
    system("pause");
    return 0;
}
