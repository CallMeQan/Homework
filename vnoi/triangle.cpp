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
const int N = 2002;

bool multiTestCases = false;

int n;
int ST[N*4];
int area(int x, int y, int m){
    
    return (int)(1/2) * 1 ;
}
struct Triangle{
    int x, y, m, value;
    Triangle(int x_, int y_, int m_){
        x = x_, y = y_, m = m_;
    }
    bool operator < (const Triangle &a) const{
        if(x != a.x) return x < a.x;
        if(y != a.y) return y < a.y;
        return m < a.m;
    }
    
} segg[N*N/4];

void update(int id, int l, int r, int pos, int k){
	if (l > pos || r < pos) return;
	if (l == r){
		ST[id] += k;
		return;
	}
    int mid = (l+r) >> 1;
	update(2*id, l, mid, pos, k);
	update(2*id + 1, mid + 1, r, pos, k);
	ST[id] = max(ST[2*id], ST[2*id+1]);
}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++){
        int x, y, m;
        cin>>x>>y>>m;
        segg[i] = Triangle(x,y,m);
    }
    sort(segg+1, segg+n+1);
    int ans = 0;
    for(int i = 1; i<=n; i++){
        update(1, 1, N-1, );
    }
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