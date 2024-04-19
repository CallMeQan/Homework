#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int N = 2e5+9;
const int inf = 1e9+1;

int n, m, S, T;

vector<int> adj[N];
bool visited[N];
int dist[N];

void bfs(int start){
    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto g: adj[val]){
            if(!visited[g]){
                visited[g] = true;
                dist[g] = min(val + 1, dist[g]);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>S>>T;
    for(int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        dist[x] = inf;
        dist[y] = inf;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(S);
    if(dist[T] == inf){
        cout<<-1;
    }else cout<<dist[T];
}
