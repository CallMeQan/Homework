#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e6+1;
int n, dp[N+5];
vector<pair<int,int>> may[N];
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.INP", "r", stdin);
    //freopen("test.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b, c; cin >> a >> b >> c;
        may[b].push_back({a, c});
    }
    dp[0] = 0;
    for(int R = 1; R <= N; R++){
        dp[R] = dp[R-1];
        int len = may[R].size();
        for(int j = 0; j < len; j++){
            int L = may[R][j].first;
            int cost = may[R][j].second;
            dp[R] = max(dp[R], dp[L] + cost);
        }
    }
    cout << dp[N];
    return 0;
}