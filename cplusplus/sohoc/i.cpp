#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	long long n;
	cin >> n;
    vector<long long> a;
	for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i*i == n) {
                a.push_back(i);
            } else {
                a.push_back(i);
                a.push_back(n/i);
            }
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}