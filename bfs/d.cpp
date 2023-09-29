/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1006
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

int n, m;
int a[N];
int moveX[] = {1,2, 2, 1,-1,-2,-2,-1}; // 8 Moves
int moveY[] = {2,1,-1,-2,-2,-1, 1, 2};
int dist[N][N];
pair<int,int> st;
pair<int,int> e;
queue<pair<int,int>> q;
void BFS()
{
    dist[st.fi][st.se] = 0;
    q.push(st);
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        for(int i = 0; i<8; i++)
        {
            int xMove = x + moveX[i];
            int yMove = y + moveY[i];
            if(xMove > 0 && yMove>0 && xMove <= 1000 && yMove <= 1000){
                if(dist[xMove][yMove] > dist[x][y] + 1){
                    dist[xMove][yMove] = dist[x][y] + 1;
                    q.push({xMove, yMove});
                }
            }
        }
        q.pop();
    }
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dist[i][j] = 1e9;
    cin>>st.fi>>st.se;
    cin>>e.fi>>e.se;
    BFS();
    if(dist[e.fi][e.se] != 1e9) cout<<dist[e.fi][e.se]<<endl;
    else cout<<-1;
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