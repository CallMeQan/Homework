#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 9;
const int INF = 1e10;

int n, m, k;
vector<pii> a[N];
int dist[1009][1009];
int truck_kun[29];

void reset(){
    for(int i = 1; i<= 1000; i++){
        for(int j = 1; j<=1000; j++){
            dist[i][j] = INF;
        }
    }
}

int bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int picked = q.front();
        q.pop();
        for(pii val: a[picked]){

        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i<=k; i++) cin>>truck_kun[i];
    sort(truck_kun+1, truck_kun+k+1);
    for(int i = 1; i<=m; i++){
        int x, y, t;
        if(t < truck_kun[1] || t > truck_kun[k]) continue;
        a[x].push_back({y, t});
        a[y].push_back({x, t});
    }
    for(int i = 1; i<=n; i++){
        reset();
        bfs(i);
        ans++;
    }
    cout<<dist[n][n];
}
