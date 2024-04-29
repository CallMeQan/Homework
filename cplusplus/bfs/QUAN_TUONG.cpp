#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 10;
const int INF = 1e9;
int y, x, t2, t1;

int dist[N][N];
char a[N][N];
int moveY[] = {2,-2, 2,-2};
int moveX[] = {2, 2,-2,-2};

void bfs(){
    queue<pii> q;
    q.push({y, x});
    dist[y][x] = 0;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int y = u.fi + moveY[i];
            int x = u.se + moveX[i];
            if(x>8 || x <= 0 || y>8 || y<=0) continue;
            if(dist[y][x] > dist[u.fi][u.se] + 1){
                dist[y][x] = dist[u.fi][u.se] + 1;
                q.push({y, x});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>y>>x>>t2>>t1;
    for(int i = 1; i<=8; i++){
        for(int j = 1; j<=8; j++) dist[i][j] = INF;
    }
    bfs();
    if(dist[t2][t1] == INF){
        cout<<-1<<endl;
    }else cout<<dist[t2][t1]<<endl;
}
