#include<bits/stdc++.h>
using namespace std;

// //Divide And Conquer
int findCrossSum(vector<int>&a,int low,int mid,int high){
    int l=INT_MIN,r=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=a[i];
        if(sum>l) l=sum;
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=a[i];
        if(sum>r) r=sum;
    }
    return r+l;
}
int findMaxSub(vector<int>&a,int low,int high){
    if (high==low) return a[low];
    int l,r,c;
    int mid=low+(high-low)/2;
    l=findMaxSub(a,low,mid);
    r=findMaxSub(a,mid+1,high);
    c=findCrossSum(a,low,mid,high);
    vector<int>arr={l,r,c};
    return *max_element(arr.begin(),arr.end());
    

}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxs=findMaxSub(a,0,n-1);
    cout<<maxs<<endl;
}


//Brute Force

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0;
    int maxs=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum>maxs){
                maxs=sum;
                l=i;
                r=j;
            }
        }
    }
    cout<<maxs<<" "<<"("<<l<<","<<r<<")"<<endl;
}
