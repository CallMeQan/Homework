#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+9;
const int INF = 9e11;
int n, m, S, T;

vector<int> g[N];
bool visited[N];
int dist[N];

void bfs(){
    queue<int> q;
    fill(dist, dist + N - 1, INF);
    fill(visited, visited + N - 1, false);
    q.push(S);
    dist[S] = 0;
    visited[S] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //cout<<"Current node "<<u<<endl;
        for(int x: g[u]){
            if(!visited[x]){
                dist[x] = dist[u] + 1;
                visited[x] = true;
                q.push(x);
                //cout<<x<<" not visited"<<endl;
            }else{
                if(dist[x] > dist[u] + 1){
                    dist[x] = dist[u] + 1;
                    q.push(x);
                    //cout<<x<<" visited but valid"<<endl;
                }//else{
                    //cout<<x<<" visited but invalid"<<endl;
                //}
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
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        //g[y].push_back(x);
    }
    bfs();
    if(visited[T]) cout<<dist[T]<<endl;
    else cout<<-1;
}
