#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define pib pair<int,bool>
using namespace std;
const int N = 1e4+6;
const int INF = 1e10;

int n, m;
vector<pii> a[106];
int must_go[N];
int dist[106];

void reset(){
    for(int i = 1; i<=n; i++){
        dist[i] = INF;
    }
}

priority_queue<pii, vector<pii>, greater<pii>> q;

void dijk(int start){
    reset();
    dist[start] = 0;
    q.push({dist[start], start});
    while(!q.empty()){
        int u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost>dist[u]) continue;;
        for(pii bruh: a[u]){
            int next_pos = bruh.first;
            int next_weight = bruh.second;
            if(dist[next_pos] > dist[u] + next_weight){
                dist[next_pos] = dist[u] + next_weight;
                q.push({dist[next_pos], next_pos});
            }
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DANGER.INP", "r", stdin);
    freopen("DANGER.OUT", "w", stdout);

    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        cin>>must_go[i];
    }
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            int tmp;
            cin>>tmp;
            if(tmp == 0) continue;
            a[i].push_back({j, tmp});
            a[j].push_back({i, tmp});
            //cout<<"From "<<i<<" to "<<j<<" is "<<a[i].size()<<endl;
        }
    }
    int ans = 0;
    for(int i = 2; i<=m; i++){
        dijk(must_go[i-1]);

        ans += dist[must_go[i]];
    }
    cout<<ans<<endl;
}
