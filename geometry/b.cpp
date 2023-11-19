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
const int N = 2e5 + 9;

bool multiTestCases = false;

int n, k;
pii a[N];

double length_of_vect(pii e){
    return sqrt(pow(e.fi, 2) + pow(e.se, 2));
}

bool comparation(pii u, pii v){
    return (length_of_vect(v) > length_of_vect(u));
}

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++) cin>>a[i].fi>>a[i].se;
    sort(a+1, a+n+1, comparation);
    cout<<decimal<<length_of_vect(a[k]);
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