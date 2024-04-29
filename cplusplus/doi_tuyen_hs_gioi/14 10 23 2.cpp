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

bool multiTestCases = true;

int q;
int dp[N+10];

void solve(){
    // Something goes here...
    cin>>q;
    cout<<dp[q]<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i<=N; i++){
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for(int b = 1; b<=N; b++){
        dp[b] = min(dp[b], dp[b-1] + 1);
        for (int a = 1; a * b <= N && a <= b; a++) {
            dp[a*b] = min(dp[a*b], dp[b] + 1);
        }
    }
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}