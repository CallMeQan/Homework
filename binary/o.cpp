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

int n;
int a[N], pre[N];

void solve(){
    // Something goes here...
	cin >> n;
	int mx = -0x3f3f3f3f3f3fll;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		pre[i] = max(pre[i - 1], x);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mx = max(mx, pre[i] * x);
		cout << mx << endl;
	}
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