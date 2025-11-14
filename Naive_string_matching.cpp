#include<bits/stdc++.h>
using namespace std;

void naivesearch(string t,string p){
    int n=t.size();
    int m=p.size();
    for(int i=0;i<n-m+1;i++){
        int j=0;
        while(j<m && t[i+j]==p[j]){
            j++;
        }
        if(j==m){
            cout<<"Pattern Found at "<<i<<endl;
        }
    }
}
int main(){
    string text="AABAACADAABAABA";
    string pattern="AABA";
    naivesearch(text,pattern);

}