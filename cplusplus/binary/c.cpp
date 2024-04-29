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

int n,k;
int a[N], b[N];

int binary_search(int l, int r) {
	int ans = -1, tmp = r;
	while (l <= r) {
		int mid = (l + r)/2;
		if (b[tmp] - b[mid - 1] <= k) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

void solve(){
    b[0] = 0;
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout<<binary_search(1, i)<<endl;
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