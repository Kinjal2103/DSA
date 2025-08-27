#include<bits/stdc++.h>
using namespace std;
vector<int> closestPair(vector<int>&a,int st,int end){
    int n=end-st+1;
    if(n==1) return {INT_MAX,-1,-1};
    if(n==2) return {abs(a[st+1]-a[st]),a[st],a[st+1]};

    int mid=st+(end-st)/2;
    vector<int> d1,d2;
    d1=closestPair(a,st,mid);
    d2=closestPair(a,mid,end);
    vector<int>ans=(d1[0] < d2[0]) ? d1 : d2;

    int l=a[mid-1],r=a[mid];
    int cross=abs(l-r);
    if(cross<ans[0]){
        ans={cross,l,r};
    }
    return ans;

}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans=closestPair(a,0,n);
    cout<<"The closest distance is "<<ans[0]<<endl<<"The numbers are "<<ans[1]<< " and "<<ans[2]<<endl;
}