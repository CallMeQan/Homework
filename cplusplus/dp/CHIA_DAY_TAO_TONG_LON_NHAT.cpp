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
const int N = 1e6 + 9;

bool multiTestCases = false;

int n,k;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i];
    for(int i = 1; i<=n; i++){
        int cur = -1e10;
        dp[i] = -1e10;
        for(int j = i; j>=1 && j>=i-k+1; j--){
            cur = max(cur, a[j]);
            dp[i] = max(dp[i], dp[j-1] + (i-j+1) * cur);
        }
    }
    cout<<dp[n];
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