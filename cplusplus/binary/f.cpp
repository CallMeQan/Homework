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

int n,p;
int a[N], b[N];

void solve() {
    int ans = 0;
    b[0] = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, value = b[i] - p;
		bool found = false;
		while (l <=	r) {
			int mid = (l + r)/2;
			if (b[mid - 1] == value) {
				found = true;
				break;
			}
			if (b[mid - 1] > value) r = mid - 1;
			else l = mid + 1;
		}
		if (found == true) ++ans;
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