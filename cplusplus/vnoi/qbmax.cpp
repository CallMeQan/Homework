/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 506
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int m,n;
int a[N][N], dp[N][N];

void solve(){
    // Something goes here...
    cin>>m>>n;
    for(int i = 1; i<= m; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i<=m;i++){
        dp[i][1] = a[i][1];
    }
    for(int j = 2; j<=n; j++){
        for(int i = 1; i <= m; i++){
            // Xét 3 hướng
            dp[i][j] = -1e9;
            if(i>1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i][j]);
            if(i<m) dp[i][j] = max(dp[i][j], dp[i+1][j-1] + a[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i][j]);
        }
    }
    int ans = -1e9;
    for(int i = 1; i<=m; i++){
        ans = max(ans, dp[i][n]);
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}