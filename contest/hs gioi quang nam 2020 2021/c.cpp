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

int n;
int a[N], b[N];
pii dp[N];
 
void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int ans = 0;
    int flag = 0;
    dp[0].fi = 0;
    dp[0].se = 0;
    for(int i = 1; i<=n; i++){
        
    }
    for(int i = 1; i <= n+1; i++){
        ans = max(ans, max(b[i]+dp[i-1], b[i]));
    }
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