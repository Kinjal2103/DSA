#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[0]<<endl;
    for(int i=1;i<n;i++){
        int curr=a[i];
        int j=i-1;
        for(;j>=0;j--){
            if(a[j]>curr){
                a[j+1]=a[j];
            }else{
                break;
            }
        }
        a[j+1]=curr;
        for(int k=0;k<=i;k++){
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
}
