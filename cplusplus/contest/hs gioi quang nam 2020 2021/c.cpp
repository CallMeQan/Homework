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
int a[N], dp[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    dp[0] = 0;
    int ans = -1;
    for(int i = 1; i<=n-1; i++){
        int tmp = a[i];
        dp[i] = 1;
        for(int j = i+1; j<=n; j++){
            if(tmp == 0) break;
            tmp += a[j];
            dp[i]++;
        }
        if(tmp == 0){
            dp[i] = max(dp[i], dp[i-1]);
        }else{
            dp[i] = 0;
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
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