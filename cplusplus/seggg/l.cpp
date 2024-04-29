/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100006
#define fi first
#define se second
#define pb push_back
#define int long long
#define array vector
#define PI 3.1459
#define endl "\n"
using namespace std;
using ull = unsigned int;
using ld = long double;

bool loopInput = false;

int n,m;
pair<int, pair<int,int>> a[4*N];
pair<int,int> ST[4*N];

void down(int id){
    int k = ST[id].se;
    if(k){
        ST[id].se = 0;
        ST[id*2].se += k;
        ST[id*2].fi += k;
        ST[id*2+1].se += k;
        ST[id*2+1].fi += k;
    }
}

void update(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return;
    if (u<=l && r<=v){
        ST[id].fi += val;
        ST[id].se += val;
        return;
    }
    down(id);
    int mid = (l+r)/2;
    update(2*id, l, mid, u, v, val);
    update(2*id + 1, mid + 1, r, u, v, val);
    
    // Checker here
    ST[id].fi = min(ST[2*id].fi, ST[2*id+1].fi);
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>a[i].se.fi >> a[i].se.se >> a[i].fi;
    }
    sort(a+1, a+n+1);
    int j = 1;
    int ans = 1e9;
    for(int i = 1; i<=n; i++){
        update(1,1,m-1, a[i].se.fi,a[i].se.se - 1, 1);
        while(ST[1].fi){
            ans = min(ans, a[i].fi - a[j].fi);
            update(1,1,m-1,a[j].se.fi,a[j].se.se -1, -1);
            j++;
        }
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}