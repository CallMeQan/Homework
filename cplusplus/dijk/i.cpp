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
#define ii pair<int,int>
#define pii pair<int, ii>
using namespace std;
const int MOD = 1e9+7;
const int N = 509;

bool multiTestCases = false;

int m, n;
int a[N][N];
vector<pii> adj[N][N];
int dist[N][N];
int moveX[3] = {0,-1, 1};
int moveY[3] = {1, 1, 1};

priority_queue<pii, vector<pii>, greater<pii>> q;

void reset(){
    for(int i = 1; i<=m; i++)
        for(int j = 1; j <=n; j++)
            dist[i][j] = 1e18;
    
}

void dijk(int x, int y){
    
}

void solve(){
    // Something goes here...
    cin>>m>>n;
    // m = row
    // n = columm

    for(int i = 1; i <= m; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j<=n; j++){
            
        }
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