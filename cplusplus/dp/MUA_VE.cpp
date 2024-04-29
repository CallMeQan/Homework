/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
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
int t[N], r[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>t[i];
    }
    for(int i = 1; i <= n-1; i++){
        cin>>r[i];
    }
    dp[1] = t[1];
    dp[2] = min(t[1]+ t[2], r[1]);
    for(int i = 3; i<=n; i++){
        dp[i] = min(dp[i-1] + t[i], dp[i-2] + r[i-1]);
    }
    cout<<dp[n];
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