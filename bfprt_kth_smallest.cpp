#include<bits/stdc++.h>
using namespace std;
int bfprt(vector<int>&a,int k){
    if(a.size()<=5){
        sort(a.begin(), a.end());
        return a[k-1];
    }
    int i=0;
    vector<int>medians;
    while(i<a.size()){
        vector<int>value;
        for(int j=0;j<5 && i<a.size();j++){
            value.push_back(a[i]);
            i++;
        }
        sort(value.begin(),value.end());
        medians.push_back(value[ceil(a.size()/2)]);
    }
    int pivot = bfprt(medians, (medians.size() + 1) / 2);
    vector<int>left,right;
    for(int i=0;i<a.size();i++){
        if(a[i]<pivot) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
    if(k==left.size()+1) return pivot;
    else if(k<=left.size()) return bfprt(left,k);
    else return bfprt(right,k-left.size());
    
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int ans=bfprt(a,k);
    cout<<ans<<endl;
}