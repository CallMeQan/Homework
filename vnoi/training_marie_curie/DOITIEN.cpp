/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 50000;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n;
int a[N];

void solve(){
    // Something goes here...
    cin>>n;
    int tienDu = n % MOD;
    cout<<50000-tienDu<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DOITIEN.INP", "r", stdin);
    freopen("DOITIEN.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}