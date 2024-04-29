#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1009;
const int INF = 1e9;
int x1, y1, x2, y2, n, m;

int dist[N][N];
char a[N][N];
int moveX[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int moveY[] = {-1,-2,-2,-1, 1, 2, 2, 1};

void bfs(){
    queue<pii> q;
    q.push({x1, y1});
    dist[x1][y1] = 0;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i<8; i++){
            int x = u.fi + moveX[i];
            int y = u.se + moveY[i];
            if(x>n || x <= 0 || y>m || y<=0) continue;
            if(dist[x][y] > dist[u.fi][u.se] + 1){
                dist[x][y] = dist[u.fi][u.se] + 1;
                q.push({x, y});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>x1>>y1>>x2>>y2;
    for(int i = 1; i<=n; i++){
        for(int j= 1; j<=m; j++) dist[i][j] = INF;
    }
    bfs();
    if(dist[x2][y2] == INF){
        cout<<-1<<endl;
    }else cout<<dist[x2][y2]<<endl;
}
