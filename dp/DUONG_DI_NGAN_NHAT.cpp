/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 106;

bool multiTestCases = false;

int n;
int a[N][N], dp[N][N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
        dp[1][i] = a[1][i];
    }
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = 1e9;
            dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j]);
            if(j>1) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i][j]);
            if(j<n) dp[i][j] = min(dp[i][j], dp[i-1][j+1] + a[i][j]);
        }
    }
    int ans = 1e9;
    for(int i = 1; i<=n; i++){
        ans = min(ans, dp[n][i]);
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}