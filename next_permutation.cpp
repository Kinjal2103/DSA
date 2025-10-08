#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a={1 ,2,3 ,6,5,4};
    int n=a.size();
    int pivot=-1;
    for(int i=n-1;i>=0;i--){
        if(a[i]<a[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        reverse(a.begin(),a.end());
    }
    for(int i=n-1;i>pivot;i--){
        if(a[i]>a[pivot]){
            swap(a[pivot],a[i]);
            break;
        }
    }
    reverse(a.begin()+pivot+1,a.end());

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}