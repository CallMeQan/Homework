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

int n, m, k;
int a[N], p[22];
bool visited[N] = {false};
vector<int> places[N];

void BFS(int i){
    queue<int> q;
    q.push(i);
	while(!q.empty()) {
		int top = q.front(); q.pop();
		for(int v : places[top]) {
			if(visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
		}
	}

}

void solve(){
    // Something goes here...
    cin>>n>>m>>k;
    int minre = 1e9;
    for(int i = 1; i<=k; i++){
        cin>>p[i];
        minre = min(minre, p[i]);
    }
    // Đk xe có trọng lượng p qua cầu có trọng lượng c là p<=c
    for(int i = 1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(c < minre) continue;
        places[a].push_back(b);
        places[b].push_back(a);
    }
    int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(visited[i] == false) 
        {
            BFS(i); 
            ans++;
        }
	}
    cout<<ans;
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