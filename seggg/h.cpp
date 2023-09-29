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

int n;
pair<int,int> a[4*N];
int ST[4*N], b[N];
int pref[N], suff[N];

void update(int id, int l, int r, int pos, int val){
    if (l > pos || r < pos) return;
    if (l == r){
        // Formular here...
        ST[id] = max(ST[id], val);
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid + 1, r, pos, val);
    
    // Checker here
    ST[id] = max(ST[2*id], ST[2*id+1]);
}

int get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return ST[id];
    
    int firstGet = get(2*id, l, (l+r)/2, u, v);
    int secondGet = get(2*id+1, (l+r)/2 + 1, r, u, v);
    // Remember to check condition...
    return max(firstGet, secondGet);
}

void solve(){
    cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
 
	sort(a + 1, a + n + 1);
 
	int id = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].first != a[i - 1].first) {
			id++;
		}
		b[a[i].second] = id;
	}
 
	for (int i = 1; i <= n; i++) {
		pref[i] = get(1, 1, n, 1, b[i] - 1) + 1;
		update(1, 1, n, b[i], pref[i]);
	}
 
	memset(ST, 0, sizeof ST);
 
	for (int i = n; i; i--) {
		suff[i] = get(1, 1, n, 1, b[i] - 1) + 1;
		update(1, 1, n, b[i], suff[i]);
	}
 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, min(pref[i], suff[i]) * 2 - 1);
	}
 
	cout << ans;

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