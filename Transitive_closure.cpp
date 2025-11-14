#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transitiveClosure(vector<vector<int>> adj) {
    int n = adj.size();
    vector<vector<int>> tc = adj;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (tc[i][k] && tc[k][j])
                    tc[i][j] = 1;
            }
        }
    }

    return tc;
}

int main() {
    vector<vector<int>> adj = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    vector<vector<int>> tc = transitiveClosure(adj);

    cout << "Transitive Closure:\n";
    for (int i=0;i<tc.size();i++) {
        for (int j=0;j<tc[i].size();j++) cout << tc[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
