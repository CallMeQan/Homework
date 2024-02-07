#include<bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int INF = 1e18;
const int N = 3e5;


int n, m, ans = 0;
ii item[N+5];
multiset<int> bag;

bool cmp(ii a, ii b){
    if(a.fi != b.fi) return a.se > b.se;
    else return a.fi < b.fi;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> item[i].fi >> item[i].se;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        bag.insert(x);
    }
    sort(item + 1, item + n + 1, cmp);
    for(int i = 1; i <= n; i++){
        int w = item[i].fi;
        auto it = bag.lower_bound(w);
        if(it == bag.end()) continue;
        else{
            ans += item[i].se;
            bag.erase(it);
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SAMPLE.INP", "r", stdin);
    freopen("SAMPLE.OUT", "w", stdout);
    solve();
    return 0;
}
