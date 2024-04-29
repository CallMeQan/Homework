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
const int N = 17;
const int MASK = 1e6+9;

bool multiTestCases = false;

int n;
int a[N][N], dp[N][MASK];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>a[i][j];
        }
    }
    memset(dp, 0x5f, sizeof(dp));
    for(int i = 0; i<n; i++){
        dp[i][1 << i] = 0;
    }
    for(int mask = 0; mask < (1 << n); mask++){ 
        vector<int> ones;
        ones.clear();
        for(int i = 0; i < n;i++)
            if((mask >> i ) & 1) ones.push_back(i);
        for(int i : ones)
        {
            for(int j : ones)
                if(i != j)
                    dp[i][mask] = min(dp[i][mask], dp[j][mask - (1 << i)] + a[j][i]);
        }
    }
    int ans = 1e18;
    for(int i = 0; i<n; i++){
        ans = min(ans, dp[i][(1<<n)-1]);
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