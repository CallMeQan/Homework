#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	cin >> n >> m;
	long long to = __gcd(n, m);
	cout << to << "\n";
    cout << n/to << " " << m/to;
    return 0;
}