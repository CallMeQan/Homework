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
const int N = 3e5 + 9;

bool multiTestCases = false;

int n, m;
pii dinh[N], tieu[N];

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>dinh[i].fi>>dinh[i].se;
    }
    cin>>m;
    for(int i = 1; i<=n; i++){
        cin>>tieu[i].fi>>tieu[i].se;
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