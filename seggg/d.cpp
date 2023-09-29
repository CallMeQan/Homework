/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100005
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

int n;
pair<int,int> a[N];
int b[N], dp[N], ST[4*N];

void update(int id, int l, int r, int i, int val){
	if (l > i || r < i) return;
	if (l == r){
		ST[id] = max(ST[id], val);
		return;
	}
	update(2*id, l, (l + r)/2, i, val);
	update(2*id + 1, (l + r)/2 + 1, r, i, val);
	ST[id] = max(ST[2*id], ST[2*id+1]);
}
 
int get(int id, int l, int r, int u, int v){
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return ST[id];
	return max(get(2*id, l, (l+r)/2, u, v), get(2*id+1, (l+r)/2 + 1, r, u, v));
}

void solve(){
    cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>a[i].fi;
		a[i].se = i;
	}
	sort(a+1, a+n+1);
	int id = 0;
	for(int i = 1; i<=n; i++){
		if(a[i].fi != a[i-1].fi){
			id++;
		}
		b[a[i].se] = id;
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		dp[i] = get(1,1,n,1,b[i]) +1;
		ans = max(ans, dp[i]);
		update(1,1,n,b[i], dp[i]);
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