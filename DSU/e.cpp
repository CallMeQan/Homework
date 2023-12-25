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
const int N = 1000005;

bool multiTestCases = false;

int n, m;
int par[N], sz[N];
int a[1005][1005], dp[N];
int movei[4] = {-1, 0, 1, 0};
int movej[4] = {0, -1, 0, 1};
vector<pii> g[N];

int fs(int v) {
    return v == par[v] ? v : par[v] = fs(par[v]);
}
 
bool us(int a, int b) {
    a = fs(a);
    b = fs(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}
 
bool inside(int x, int y){
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}
 
int conv(int x, int y){
    return (x - 1) * m + y;
}
 
int conv(pii x){
    return (x.fi - 1) * m + x.se;
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            par[conv(i, j)] = conv(i, j);
            sz[conv(i, j)] = 1;
        }
    }
    set<int> s;
    map<int,int> map;
    for(int i=1; i<=n; i++) {
        for(int j= 1; j<= m; j++) {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }
    int pos = 1;
    for(int x: s){
        map[x] = pos;
        pos++;
    }
    pos --;
    for(int i=1; i<=n; i++) {
        for(int j= 1; j<= m; j++) {
            a[i][j] = map[a[i][j]];
            g[a[i][j]].pb({i, j});
        }
    }
    int cur = 0;
    dp[pos] = 0;
    for(int day = pos; day >= 0; day--){
        for(auto x: g[day + 1]){
            int i = x.fi, j = x.se;
            if (a[i][j] == day + 1){
                cur ++;
                for(int k= 0;k<= 3; k++){
                    int i2 = i + movei[k], j2 = j + movej[k];
                    if (!inside(i2, j2)) continue;
                    if (a[i2][j2] >= day + 1) {
                        if (us(conv(i,j), conv(i2,j2))) cur--;
                    }
                }
            }
        }
        dp[day] = cur;
    }
    vector<int> v;
    v.pb(0);
    for(auto x: s) v.pb(x);
    int k; cin >> k;
    while (k--){
        int x; cin >> x;
        int l = 0, r = pos, res = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (v[mid] <= x) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << dp[res] << '\n';
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