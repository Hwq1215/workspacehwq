#include<bits/stdc++.h>
using namespace std;
const int length = 10000;
int temp[length];
int res = 0;
void Merge(int *array,int first,int mid,int last);
void MergeSort(int *array,int first,int last);

int main(){
    int array[length];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&array[i]);
    }
    MergeSort(array,0,n-1);
    cout<<res;
system("pause");
return 0;
}

void Merge(int *array,int first,int mid,int last){
    int cur = 0;
    int i = first , j = mid + 1;
    while(i<=mid&&j<=last){
        if(array[i]<array[j]){
            temp[cur++] = array[i++];
        }else{
            temp[cur++] = array[j++];
            res += mid - i + 1;
        }
    }
    while(i<=mid){
        temp[cur++] = array[i++];
    } 
    while (j<=last)
    {
        temp[cur++] = array[j++];
    }
    for(int m = 0;m<cur;m++){
        array[first + m] = temp[m];
    }
}

void MergeSort(int *array,int first,int last){
    if(first == last){
    return;
    } 
    int mid = (first + last)>>1;
    MergeSort(array,first,mid);
    MergeSort(array,mid+1,last);
    Merge(array,first,mid,last);
}

