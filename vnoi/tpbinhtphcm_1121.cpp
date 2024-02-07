/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <algorithm>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n, m;
int a[N];

void solve(){
    // Something goes here...
    cin>>m>>n;
    cout<<__gcd(m, n);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UCLN.INP", "r", stdin);
    freopen("UCLN.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
