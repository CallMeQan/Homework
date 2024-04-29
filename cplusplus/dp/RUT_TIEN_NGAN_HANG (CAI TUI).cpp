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
const int N = 500;

bool multiTestCases = false;

int n,m;
int a[N], dp[N][10001];

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    dp[0][0] = 0;
    for(int i = 1; i<=m; i++){
        dp[0][i] = 1e18;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=m; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i])
                dp[i][j] = min(dp[i][j], dp[i][j-a[i]] + 1);
        }
    }
    cout<<dp[n][m];
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