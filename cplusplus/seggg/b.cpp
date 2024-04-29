/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 200006
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
const int inf = 1e9;

bool loopInput = false;

int n, q, l, r;
int ST_MAX[4*N], ST_MIN[N*4], a[N];
 
void build(int id, int l, int r) {
    if(l == r){
        ST_MIN[id] = ST_MAX[id] = a[l];
    }
    int mid = (l+r)/2;
    build(2*id, l, mid);
	build(2*id + 1, mid + 1, r);
    ST_MIN[id] = min(ST_MIN[id*2], ST_MIN[id*2+1]);
    ST_MAX[id] = max(ST_MAX[id*2], ST_MAX[id*2+1]);
}
 
int getMax(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return -inf;
    }
 
    if (u <= l && r <= v) {
        return ST_MAX[id];
    }
 
    int mid = (l + r) / 2;
    return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int getMin(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return inf;
    }
 
    if (u <= l && r <= v) {
        return ST_MIN[id];
    }
 
    int mid = (l + r) / 2;
    return min(getMin(id * 2, l, mid, u, v), getMin(id * 2 + 1, mid + 1, r, u, v));
}


void solve(){
    cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
 
	build(1, 1, n);
 
	while (q--) {
		int A, B;
		cin >> A >> B;
		cout << getMax(1, 1, n, A, B) - getMin(1, 1, n, A, B) << '\n';
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >>n>>t;
        while (t--) solve();
    } else solve();
}