#include<bits/stdc++.h>
using namespace std;

vector<int> buildlps(string p){
    int m=p.size();
    vector<int> ans(m,0);
    int k=0;
    for(int i=1;i<m;i++){
        while(k>0 && p[k]!=p[i]){
            k=ans[k-1];
        }
        if(p[k]==p[i]){
            k=k+1;
        }
        ans[i]=k;
    }
    return ans;
}
void KMP(string t,string p){
    int n=t.size();
    int m=p.size();

    vector<int> lps=buildlps(p);

    int q=0;
    for(int i=0;i<n;i++){
        while(q>0 && p[q]!=t[i]){
            q=lps[q-1];
        }
        if(p[q]==t[i]){
            q++;
        }
        if (q == m) {
            cout << "Pattern found at index " << (i - m+1) << "\n";
            q = lps[q-1];  
        }
    }
    
}
int main(){
    string text="AABAACADAABAABA";
    string pattern="AABA";

    KMP(text, pattern);
}