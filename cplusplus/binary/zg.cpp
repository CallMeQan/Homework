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

int n, k;
int a[N];

bool check(int mid) {
    int pos = a[1], ans = 1;
    for (int i = 2; i <= n; i++) {
        if (pos + mid*2 < a[i]) {
            pos = a[i];
            ans++;
        }
    }
    return ans <= k;
}

int binarySearch(int l, int r){
    int res = 0;
	while(l <= r) {
		int m = (l + r) / 2;
		if (check(m)) {
			res = m;
			r = m -1;
		} else  l = m + 1;
	}
	return res;
}

void solve(){
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    int r = a[n] - a[1];
    cout<< binarySearch(1, r);
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