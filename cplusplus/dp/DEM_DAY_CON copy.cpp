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
const int N = 1006;

bool multiTestCases = false;

int n;
int a[N], dp[N][N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i =1; i<=n; i++) {
        cin>>a[i];
        dp[i][i] = 1;
    }
    for(int i = 1; i<=n; i++){

    }
    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }
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