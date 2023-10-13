/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = true;

int n;
int a[N];
int f[N], vf[N];

int sqr(int x) {
	return x * x;
}
 
int pow(int a, int b) {
	if (b == 0) return 1 % MOD;
	else 
		if (b % 2 == 0) 
			return sqr(pow(a, b / 2)) % MOD;
		else return a * (sqr(pow(a, b / 2)) % MOD) % MOD;
}
 
int C(int n, int k) {
	return f[n] * vf[n - k] % MOD * vf[k] % MOD; 
}

void solve(){
    // Something goes here...
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
	for (int i = 1; i <= N; i++) 
		f[i] = f[i - 1] * i % MOD;
	vf[0] = 1;
	for (int i = 1; i <= N; i++) 
		vf[i] = pow(f[i], MOD - 2);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}