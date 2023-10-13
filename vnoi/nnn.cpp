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

bool multiTestCases = false;

int a[N];
int cnt = 0;
bool prime[N];

void sieve() {
	fill(prime, prime + N + 1, true);
	prime[1] = false;
	for (int i = 2; i <= sqrt(N); i++) {
		if (prime[i]) {
			for (int j = i*i; j <= N; j += i) prime[j] = false;
		}
	}
	for (int i = 2; i <= N; i++) 
		if (prime[i]) a[++cnt] = i;
}
 
bool check(int n) {
	for (int i = 1; i <= cnt; i++) {
		if (a[i] > sqrt(n)) break;
		if (n % a[i] == 0) return false;
	}
	return n>1;
} 

void solve(){
    // Something goes here...
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}