#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 1;
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
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
	int n, x, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (check(x)) ++ans;
	}
	cout << ans;
}