#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e9+7;

void solve(){
    int n;
    cin>>n;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }

    // Dp stuff
    int dp[n+1][2];
    for(int i = 0; i<=n; i++){
        dp[i][1] = dp[i][0] = INF;
    }
    dp[0][1] = 0;
    dp[1][0] = a[1];

    for(int i = 2; i<=n; i++){
        dp[i][0] = min(dp[i-1][1] + a[i], dp[i-2][1] + a[i] + a[i-1]);
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }
    cout<<min(dp[n][1], dp[n][0])<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
