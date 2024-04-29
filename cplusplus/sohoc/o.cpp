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

bool isPrime(int n){
    for (int i = 2; i <= sqrt(n); i++) 
		if (n % i == 0) return false;
	return n > 1;
}

void solve(){
    int ans = 0;
    cin >> n;
	if (isPrime(n)) cout << 1;
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			int somu = 0;
			while (n % i == 0) {
				n /= i;
				somu++;
			}
			if (somu > ans) ans = somu;
		}
		cout << ans;
	}
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}