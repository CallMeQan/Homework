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
int a[N], dp[N];

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]), dp[i-2] + abs(a[i-2] - a[i]));
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