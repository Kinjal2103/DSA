#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &a,int t , vector<int>&curr,int sum){
    if(sum==t){
        for(int b:curr){
            cout<<b<<" ";
        }
        cout<<endl;
        return;
    }

    if(i>=a.size() || sum>t) return;

    curr.push_back(a[i]);
    solve(i+1,a,t,curr,sum+a[i]);

    curr.pop_back();
    solve(i+1,a,t,curr,sum);
}
int main(){
    vector<int> a={3,4,5,6};
    int target =9;

    vector<int> current;
    cout<<"Subsets with sum = "<<target<<endl;
    solve(0,a,target,current,0);
}