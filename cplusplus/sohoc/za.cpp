#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5+1;
long long n;
long long a[N];
long long mod = 1e9 +7;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; i++) 
        a[i] = (a[i - 1] + a[i - 2]) % mod;
    cout << a[n];
}