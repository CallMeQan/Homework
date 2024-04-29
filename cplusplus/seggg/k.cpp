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

int n, D;
pair<int,int> a[4*N];
int ST[4*N];
bool have[N];

void build(int id, int l, int r){
    if(l == r){
        ST[id] = a[l].se;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    ST[id] = max(ST[id*2], ST[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return ST[id];
    int mid = (l+r)/2;
    int firstGet = get(2*id, l, mid, u, v);
    int secondGet = get(2*id+1, mid + 1, r, u, v);
    // Remember to check condition...
    return max(firstGet, secondGet);
}

void solve(){
    cin >> n >> D;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a + 1, a + n + 1);
 
	build(1, 1, n);
 
	int j = 1;
	for (int i = 1; i <= n; i++) {
		while (a[j].first < a[i].first - D) {
			j++;
		}
		if (get(1, 1, n, j, i - 1) >= 2 * a[i].second) {
			have[i] = true;
		}
	}
 
	int ans = 0;
	j = n;
	for (int i = n; i; i--) {
		while (a[j].first > a[i].first + D) {
			j--;
		}
		if (have[i] && get(1, 1, n, i + 1, j) >= 2 * a[i].second) {
			ans++;			
		}
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