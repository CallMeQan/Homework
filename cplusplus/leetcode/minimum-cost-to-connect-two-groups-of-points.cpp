/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;




vector<vector<int>>& cost
int solve(){
    const int inf = 1e9;
    int dp[13][(1 << 12) + 5];
    int sumCost[13][(1 << 12) + 5];
    vector <int> listMask[(1 << 12) + 5];
    int n = (int) cost.size();
    int m = (int) cost[0].size();
    for (int i = 0; i <= n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            dp[i][mask] = inf;
            sumCost[i][mask] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int j = 0; j < m; j++) {
                if ((mask & (1 << j)) > 0) {
                    sumCost[i][mask] += cost[i][j];
                }
            }
        }
    }
    for (int mask = 0; mask < (1 << m); mask++) {
        listMask[mask].clear();
        for (int nextmask = 1; nextmask < (1 << m); nextmask++) {
            if ((mask & nextmask) == 0) {
                listMask[mask].push_back(nextmask);
                continue;
            }
            if ((mask & nextmask) == nextmask) {
                listMask[mask].push_back(nextmask);
                continue;
            }
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            if (dp[i][mask] == inf) {
                continue;
            }
            for (int j = 0; j < (int) listMask[mask].size(); j++) {
                int nextmask = listMask[mask][j];
                dp[i + 1][mask | nextmask] = min(dp[i + 1][mask | nextmask], dp[i][mask] + sumCost[i][nextmask]);
            }
        }
    }
    return dp[n][(1 << m) - 1];

}

signed main(){
    fast;
    cin>>x;
    cout<<solve();
}
