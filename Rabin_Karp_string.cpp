#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string t,string p){
    int n=t.size();
    int m=p.size();
    int d=10,q=13;
    int h=1;
    for(int i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    int P=0,t0=0;
    for(int i=0;i<m;i++){
        P=(d*P+ p[i])%q;
        t0=(d*t0 + t[i])%q;
    } 
    for(int i=0;i<n-m+1;i++){
        if(P==t0){
            bool match=true;
            for(int j=0;j<m;j++){
                if(t[i+j]!=p[j]){
                    match=false;
                    break;
                }
            }
            if(match) cout << "Pattern found at index " << i << "\n";
        }
        if(i<n-m){
            t0=(d*(t0-t[i]*h)+t[i+m])%q;
            if(t0<0) t0=t0+q;
        }
    }
}
int main(){
    string t="AABAACAADAABAABA";
    string p = "AABA";
    rabinKarp(t,p);
}