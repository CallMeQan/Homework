/*
    author: Qan
*/
#include <bits/stdc++.h>
#define N 1009
#define int long long
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;
int n;
int a[4*N];
int ST[4*N];

void build(int id, int l, int r) {
    if(l < 1 || r > n || id > 4*N-1 || id < 1) return;
    if(l == r){
        ST[id] = 1;
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
	build(2*id + 1, mid + 1, r);
    ST[id] = (ST[id*2] + ST[id*2+1]) % MOD;
}

int get(int id, int l, int r, int u, int v){
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return ST[id];
	return (get(2*id, l, (l+r)/2, u, v) + get(2*id+1, (l+r)/2 + 1, r, u, v)) % MOD;
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    int q, l, r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<get(1, 1, n, l, r)<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}