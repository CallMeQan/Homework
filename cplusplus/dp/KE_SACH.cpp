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
const int N = 2006;

bool multiTestCases = false;

int n, L;
int H[N];
int W[N];
int dp[N];

void solve(){
    // Something goes here...
    cin>>n>>L;
    for(int i = 1; i <= n; i++){
        cin>>H[i]>>W[i];
    }
    for(int i = 1; i <= n; i++){
        int tmp = H[i];
        int sum = W[i];
        dp[i] = H[i] + dp[i-1];
        for(int j = i-1; j >= 1; j--){
            tmp = max(tmp, H[j]);
            sum += W[j];
            if(sum > L) break;
            dp[i] = min(dp[i], dp[j-1] + tmp);
        }
    }
    cout << dp[n];
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