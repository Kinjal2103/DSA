#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> task={
        {1,4},{2,14},{3,5},{3,8},{4,6},{5,7},{7,9},{8,12},{8,13},{10,11},{13,15}
    };

    sort(task.begin(),task.end(),[&](vector<int> a,vector<int> b){
        return a[1]<b[1];
    });

    vector<vector<int>> ans;
    int end=0;
    for(auto it:task){
        if(end<=it[0]){
            ans.push_back(it);
            end=it[1];
        }
        
    }

    for(auto it: ans){
        cout << it[0] << " " << it[1] << endl;
    }
}