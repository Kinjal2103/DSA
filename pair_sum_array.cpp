//Given a sorted array return pair with target sum
//Brute Force find all pairs and check if the target is achieved - o(n^2)
//Optimal TWO POINTER

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n-1;
    while(l<r){
        if(a[l]+a[r]>target) r--;
        else if (a[l]+a[r]<target) l++;
        else {
            cout<<a[l]<<" "<<a[r]<<endl;
            break;
        }
    }
}
