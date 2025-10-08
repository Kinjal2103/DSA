#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int st=0,end=s.length()-1;
    while(st<end){
        if(s[st]==s[end]){
            st++;
            end--;
        }
        else {
            cout<<"False"<<endl;
            return 0;
        }
    }
    cout<<"True"<<endl;
    return 0;
}