/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 65
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ld = long double;

bool loopInput = false;

int n;
int a[N], dp[N][3];

void solve(){
    cin>>n;
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
    }
    cout<<dp[n][0] + dp[n][1] + dp[n][2];
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