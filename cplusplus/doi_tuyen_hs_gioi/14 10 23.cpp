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
const int N = 1e6;

bool multiTestCases = false;

int n, ans = 0;
int a[N], cnt[N], dp[N];

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    dp[1] = cnt[1];
    for(int i = 1; i<=N; i++){
        for(int j = 2 * i; j<=N; j += i){
            dp[j] = max(dp[j], dp[i] + cnt[j]);
        }
        ans = max(ans, dp[i]);
    }
    cout<<n - ans<<endl;
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