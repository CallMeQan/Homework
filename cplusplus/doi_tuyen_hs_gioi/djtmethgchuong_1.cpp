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

int n, m;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=m; i++) dp[i] = 1e9;
    for(int i = 1 ; i<=n; i++){
        cin>>a[i];
    }
    dp[0] = 0;
    for(int i = 1; i<=m; i++) {
        for(int j = 1; j<=n; j++){
            if(i - a[j] >= 0)
                dp[i] = min(dp[i], dp[i-a[j]]+1);
        }
    }
    if(dp[m] == 1e9) cout<<-1;
    else cout<<dp[m];
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