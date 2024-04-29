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

int n, s;
int a[109], dp[N];

void solve(){
    // Something goes here...
    cin>>n>>s;
    for(int i = 1; i<=n; i++) cin>>a[i];
    dp[0] = 1;
    for(int i = 1; i<=s; i++){
        for(int j = 1; j<=n; j++){
            if(i - a[j] >= 0){
                dp[i] = (dp[i] + dp[i-a[j]]) % MOD;
            }
        }
    }
    cout<<dp[s];
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