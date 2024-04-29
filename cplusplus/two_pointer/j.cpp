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
const int N = 1.5*1e6 + 9;

bool multiTestCases = false;

int n, m;
int a[N], cnt[N];
set<int> ds;

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1;i<=m; i++){
        cnt[a[i]]++;
    }
    for(int i= 0; i<=N;i++){
        if(!cnt[i]) ds.insert(i);
    }
    cout<<*ds.begin()<<" ";
    for(int i = m + 1; i<=n; i++){
        if(!cnt[a[i]]++){
            ds.erase(a[i]);
        }
        if(!--cnt[a[i-m]]){
            ds.insert(a[i-m]);
        }
        cout<<*ds.begin()<<" ";
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
