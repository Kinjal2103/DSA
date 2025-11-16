//Finite Automata

//DIDNT UNDERSTAND AT ALL!!!


#include<bits/stdc++.h>
using namespace std;

int nextState(string &p,int m,int i,char c){
    if(i<m && p[i]==c){
        return i+1;
    }
    for(int j=i;j>0;j--){
        if(p[j-1]==c){
            int ok=1;
            for(int k=0;k<j-1;k++){
                if(p[k]!=p[i-j+1+k]){
                    ok=0;
                    break;
                }
            }
            if(ok) return j;
        }
    }
    return 0;
}
void buildFA(string &p,vector< unordered_map<char, int> > &FA){
    int m=p.length();
    for(int i=0;i<=m;i++){
        for(char c:p){
            FA[i][c]=nextState(p,m,i,c);
        }
    }
}
int finiteAutomata(string &t,string &p){
    int n=t.length();
    int m=p.length();
    vector< unordered_map<char, int> > FA(m+ 1);
    buildFA(p,FA);
    int state=0;
    for(int i=0;i<n;i++){
        char c=t[i];
        if(FA[state].count(c))
            state=FA[state][c];
        else state=0;
        if(state==m){
            return i+1-m;
        }
    }
    return -1;
}
int main(){
    string text="AABAACADAABAABA";
    string pattern="AABA";

    int index=finiteAutomata(text,pattern);

    if (index == -1)
        cout << "Pattern not found\n";
    else
        cout << "Pattern found at 0-based index = " << index << endl;

}