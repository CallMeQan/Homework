/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
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

int n,m,k,ans;

void solve(){
    // Something goes here...
    cin >> n >> m >> k;
	int l = 1, r = n * m;
	while (l <= r) {
		int mid = (l + r)/2;
		int tmp = 0;
		for (int i = 1; i <= n; i++)
			tmp += min(m, mid/i);
		if (tmp >= k) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
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