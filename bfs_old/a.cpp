/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 106
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

int n,m;
char a[N][N];
pair<int,int> start;
pair<int,int> endp;
int dist[N][N];
queue<pair<int,int>> q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void BFS(){
    dist[start.fi][start.se] = 0;
    q.push(start);
    while(!q.empty()){
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for(int s = 0; s<4; s++){
            int x = u + dx[s];
            int y = v + dy[s];
            if( !(x>0 && x<=n && y >0 && y<=m && a[x][y] != '*')) continue;
            if(dist[x][y] > dist[u][v] + 1){
                dist[x][y] = dist[u][v] +1;
                q.push(make_pair(x,y));
            }
        }
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            dist[i][j] = 1e9;
            char c;
            cin>>c;
            a[i][j] = c;
            if(c == 'B') start = make_pair(i,j);
            else if(c == 'C') endp = make_pair(i,j);
        }
    }
    BFS();
    if (dist[endp.fi][endp.se] == 1e9) cout << -1; 
    else cout << dist[endp.fi][endp.se];
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