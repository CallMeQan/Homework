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

int n, oneDay, sevenDay, thirtyDay;
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n>>oneDay>>sevenDay>>thirtyDay;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        if(a[i] == 0){
            dp[i] = dp[i-1];
            continue;
        }
        int bruh = dp[i-1] + oneDay;
        int lmao = dp[max((int)0, i-7)] + sevenDay;
        int wtf = dp[max((int)0, i-30)] + thirtyDay;
        dp[i] = min(bruh, min(lmao, wtf));
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