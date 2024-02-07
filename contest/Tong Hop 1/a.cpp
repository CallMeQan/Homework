#include <bits/stdc++.h>
#define int long long
#define endl "\n";
using namespace std;
const int N = 101;
const int INF = 1e7;
const int MAX_K = 1e6 + 1;

int n, k;
int a[N], dp[N][MAX_K];

void solve(){
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i];
    dp[0][0] = 0;

    for(int i = 1; i<=k; i++) dp[0][i] = INF;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i]){
                dp[i][j] = min(dp[i][j], dp[i][j-a[i]] + 1);
            }
        }
    }
    if(dp[n][k] == INF){
        cout<<-1;
    }else cout<<dp[n][k];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
