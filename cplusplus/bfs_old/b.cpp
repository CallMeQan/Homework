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
int ans = 0;
bool ok[N];
array<int> g[N];

void BFS(){
    queue<int>q;
	q.push(k);
	ans = 1;
	ok[k] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(auto vv : g[v]) {
			if(ok[vv] == false) {
				ok[vv] = true;
				ans++;
				q.push(vv);
			}
		}
	}

}

void solve(){
    // Something goes here...
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        int x; cin>>x;
        for(int j = 1; j<=x;j++){
            cin>>a[i];
            g[i].push_back(a[i]);
        }
    }
    BFS();
    cout << ans << '\n';
	for(int i = 1 ; i <= n ; i++) {
		if(ok[i]) cout << i <<  ' ';
	}
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