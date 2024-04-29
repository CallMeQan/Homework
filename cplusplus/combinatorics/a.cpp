/*
    author: Qan
*/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 1;

int n, k, t;
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
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<C(n,k)<<endl;
    }
}