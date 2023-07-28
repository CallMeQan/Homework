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
int a[N], b[N],c[N];

void solve(){
    // Something goes here...
    cin>>n;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    b[0] = c[n + 1] = 0;
	for (int i = 1; i <= n; i++) 
		b[i] = max(b[i - 1],a[i]);
	for (int i = n; i > 0; i--)
		c[i] = max(c[i + 1],a[i]);
	for (int i = 1; i <= n; i++)
		ans += min(b[i], c[i]) - a[i];
	cout << ans << "\n";
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