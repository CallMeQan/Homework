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
int a[N];
int ST[4*N];

void update(int id, int l, int r, int i, int val){
	if (l > i || r < i) return;
	if (l == r){
		ST[id] += val;
		return;
	}
	update(2*id, l, (l + r)/2, i, val);
	update(2*id + 1, (l + r)/2 + 1, r, i, val);
	ST[id] = ST[2*id] + ST[2*id+1];
}
 
int get(int id, int l, int r, int u, int v){
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return ST[id];
	return get(2*id, l, (l+r)/2, u, v) + get(2*id+1, (l+r)/2 + 1, r, u, v);
}

void solve(){
    cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans += get(1,1,1e5, a[i]+1, 1e5);
		update(1,1,1e5, a[i], 1);
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