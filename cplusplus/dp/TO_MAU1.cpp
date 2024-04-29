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
const int N = 1e5 + 9;

bool multiTestCases = false;

int n;
int a[N][4], dp[N][4];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];
    dp[1][3] = a[1][3];
    for(int i = 2; i<=n; i++){
        dp[i][1] = min(dp[i-1][2] + a[i][1], dp[i-1][3] + a[i][1]);
        dp[i][2] = min(dp[i-1][1] + a[i][2], dp[i-1][3] + a[i][2]);
        dp[i][3] = min(dp[i-1][1] + a[i][3], dp[i-1][2] + a[i][3]);
    }
    int ans = min(dp[n][1], min(dp[n][2], dp[n][3]));
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