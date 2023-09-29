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
int mod = 1e9;
int n, k;
int a[N];
int ST[11][4*N], dp[4*N][11];

void update(int j, int id, int l, int r, int i, int val){
	if (l > i || r < i) return;
	if (l == r){
		ST[j][id] = (ST[j][id] + val) % mod;
		return;
	}
	update(j,2*id, l, (l + r)/2, i, val);
	update(j,2*id + 1, (l + r)/2 + 1, r, i, val);
	ST[j][id] = (ST[j][2*id] + ST[j][2*id+1]) % mod;
}
 
int get(int j,int id, int l, int r, int u, int v){
	if (l > v || r < u) return 0;
	if (u <= l && r <= v) return ST[j][id];
	return get(j,2*id, l, (l+r)/2, u, v) + get(j,2*id+1, (l+r)/2 + 1, r, u, v);
}
void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n;i++)cin>>a[i];
    for(int i = 1; i<=n; i++){
        dp[i][1] = 1;
        for(int j = 2; j<=k; j++)
            dp[i][j] = get(j-1, 1, 1, n, a[i] +1, n);
        for(int j = 1; j<k; j++)
            update(j,1,1,n,a[i], dp[i][j]);
    }
    int ans = 0;
    for(int i= 1; i<=n; i++)
        ans = (ans+dp[i][k]) % mod;
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