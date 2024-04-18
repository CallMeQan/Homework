#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 106;
const int INF = 1e9;
int R, C;

int dist[N][N];
char a[N][N];
pii startP;
pii endP;
int moveY[] = {1,-1, 0, 0};
int moveX[] = {0, 0,-1, 1};

void bfs(){
    queue<pii> q;
    q.push(startP);
    dist[startP.fi][startP.se] = 0;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int x = u.fi + moveX[i];
            int y = u.se + moveY[i];
            if(x>R || x <= 0 || y>C || y<=0 || a[x][y] == '*') continue;
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

    cin>>R>>C;
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++){
            cin>>a[i][j];
            dist[i][j] = INF;
            if(a[i][j] == 'B'){
                startP = {i, j};
            }else if(a[i][j] == 'C'){
                endP = {i, j};
            }
        }
    }
    bfs();
    if(dist[endP.fi][endP.se] == INF){
        cout<<-1<<endl;
    }else cout<<dist[endP.fi][endP.se]<<endl;
}
