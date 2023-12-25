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
int a[N], dp[N][2];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    int ans = -1;
    for(int i = 1; i<=n; i++){
        if(a[i]){
            dp[i][1] = dp[i-1][1]+1;
            dp[i][0] = dp[i-1][0]+1;
        }else{
            dp[i][1] = dp[i-1][0]+1;
            dp[i][0] = 0;
        }
        ans = max(ans,dp[i][1]);
    }
    cout<<ans-1;
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