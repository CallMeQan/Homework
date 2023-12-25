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
#define decimal fixed<<setprecision(6)
using namespace std;
const int MOD = 1e9+7;
const int N = 3e5 + 9;

bool multiTestCases = false;

int n, k;
int a[N];
double dp[N];

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<=n; i++){
        int tmp = a[i];
        int l = i+k;
        for(int j = i+1; j<=i+k;j++){
            tmp += a[j];
            cout<<a[j]<<endl;
        }
        
        dp[i] = (double) tmp / (double) l;
        
    }
    double ans = 0.0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp[i]);
    }
    cout<<fixed<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("RATE.INP", "r", stdin);
    //freopen("RATE.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}