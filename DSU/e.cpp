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

int n, m;
// m la dong, n la cot
int a[1005][1005], par[N];
int ans = 0;

bool checked[N];
vector<pair<int,pii>> bruh;
vector<pii> q;

int acs(int x){
	if(par[x]==x)return x;
	else return par[x]=acs(par[x]);
}
void join(int u,int v){
	int x=acs(u);
	int y=acs(v);
	if(x!=y){
		par[x]=y;
	}
}

void bfs(int start){
    
}

void solve(){
    // Something goes here...
    cin>>m>>n;

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