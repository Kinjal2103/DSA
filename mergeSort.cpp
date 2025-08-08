#include<bits/stdc++.h>
using namespace std;
int ans=0;

void merge(vector<int> &a,int start,int mid,int end){
    int s1=mid-start+1;
    int s2=end-mid;
    vector<int>left(s1) , right(s2);
    for(int i=0;i<s1;i++){
        left[i]=a[start+i];
    }
    for(int i=0;i<s2;i++){
        right[i]=a[mid+i+1];
    }
    int i=0,j=0,k=start;
    while(i<s1 && j<s2){
        ans++;
        if(left[i]>right[j]){
            a[k++]=right[j++];
        }else{
            a[k++]=left[i++];
        }
    }
    while(i<s1)
        a[k++]=left[i++];
    while(j<s2)
        a[k++]=right[j++];
}
void mergeSort(vector<int> &a,int start,int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;

    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,mid,end);

}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    cout<<ans<<endl;
}
