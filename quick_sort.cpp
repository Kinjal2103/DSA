#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&a,int low,int high){
    int pivot=a[low];
    int l=low+1,r=high;
    while(l<=r){
        while(a[l]<pivot) l++;
        while(a[r]>pivot) r--;
        if(l<r){
            swap(a[l],a[r]);
        }
    }
    swap(a[r],a[low]);
    return r;
}
void quickSort(vector<int>&a,int low,int high){
    if(low<high){
        int pivot=partition(a,low,high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}