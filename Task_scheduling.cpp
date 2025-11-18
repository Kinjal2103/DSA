#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> job = {
        {4, 70},
        {2, 60},
        {4, 50},
        {3, 40},
        {1, 30},
        {4, 20},
        {6, 10}
    };

    sort(job.begin(),job.end(),[&](auto &a,auto &b){
        return a[1]>b[1];
    });

    int lastday=0;
    for(auto &it:job){
        lastday=max(lastday,it[0]);
    }
    vector<int> slot(lastday+1,-1);
    int total=0;

    for(int i=0;i<job.size();i++){
        for(int j=job[i][0];j>0;j--){
            if(slot[j]==-1){
                slot[j]=job[i][1];
                total+=job[i][1];
                break;
            }
        }
    }
    cout << "Total Profit: " << total << endl;
}