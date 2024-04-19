#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define rep(i, l, r) for(int i = l; i <= r; i++)

using namespace std;

typedef pair<int,int> ii;
const int N = 3e5;

int n, m;
ii a[N+5];
int c[N+5], max_r[N+5];
multiset<int> s;

void solve(){
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i].fi >> a[i].se;
    rep(i, 1, m) cin >> c[i];
    sort(a+1, a+1+n); sort(c+1, c+1+m);
    int j = 0;
    rep(i, 1, m){
        while (j < n && a[j+1].fi <= c[i]) j++;
        max_r[i] = j;
    }
    j = 0;
    int ans = 0;
    rep(i, 1, m){
        while (j < max_r[i]) {
            s.insert(a[++j].se);
        }
        if (s.size()) {
            ans += *s.rbegin();
            s.erase(s.find(*s.rbegin()));
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SAMPLE.INP", "r", stdin);
    freopen("SAMPLE.OUT", "w", stdout);
    solve();
}
