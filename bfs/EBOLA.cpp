#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 9;
const int INF = 1e9;

int n, k;
vector<int> a[N];
vector<int> infected;
bool visited[N];

void bfs(){
    queue<int> q;
    q.push(k);
    visited[k] = true;
    infected.push_back(k);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: a[u]){
            if(!visited[v]){
                visited[v] = true;
                infected.push_back(v);
                q.push(v);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        int m;
        cin>>m;
        if(m == 0) continue;
        for(int j = 1; j<=m; j++){
            int pe;
            cin>>pe;
            a[i].push_back(pe);
        }
    }
    bfs();
    sort(infected.begin(), infected.end());
    cout<<infected.size()<<endl;
    for(int i: infected) cout<<i<<" ";
}
