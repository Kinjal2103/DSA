#include<bits/stdc++.h>
using namespace std;

double knapsack(vector<double> &value,vector<double> &weight,double W){
    int n=value.size();
    vector<int> idx(n);

    for(int i=0;i<n;i++){
        idx[i]=i;
    }
    sort(idx.begin(),idx.end(),[&](int a,int b){
        return (value[a]/weight[a]>value[b]/weight[b]);
    });

    double total=0.0;
    for(int i=0;i<n;i++){
        int k=idx[i];
        if(W==0) break;
        if(weight[i]<=W){
            total+=value[i];
            W-=weight[i];
        }
        else{
            double frac=W/weight[i];
            total+=value[i]*frac;
            break;
        }
    }
    return total;
}
int main(){
    vector<double> value={30,100,160,90,20};
    vector<double> weight={5,20,40,30,10};
    double W=60;

    cout<<knapsack(value,weight,W)<<endl;
}