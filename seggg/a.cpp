/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 100006
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

bool loopInput = true;

int n, q;
int a[4*N];

void update(int id, int l, int r, int pos, int k){
	if (l > pos || r < pos) return;
	if (l == r){
		a[id] += k;
		return;
	}
	update(2*id, l, (l + r)/2, pos, k);
	update(2*id + 1, (l + r)/2 + 1, r, pos, k);
	a[id] = max(a[2*id], a[2*id+1]);
}
 
int get(int id, int l, int r, int u, int v){
	if (l > v || r < u) return -1e18;
	if (u <= l && r <= v) return a[id];
	return max(get(2*id, l, (l+r)/2, u, v), get(2*id+1, (l+r)/2 + 1, r, u, v));
}

void solve(){
    int type;
    cin>>type;
    if(type==0){
        int pos, k;
        cin>>pos>>k;
        update(1,1,n,pos,k);
    }else{
        int x, y;
        cin>>x>>y;
        cout<<get(1,1,n,x,y)<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (loopInput){
        int t; cin >>n>>t;
        while (t--) solve();
    } else solve();
}