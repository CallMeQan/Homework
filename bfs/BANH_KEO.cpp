/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1009;

bool multiTestCases = false;

int n, m, k;
int a[N];
vector<int> cities[N];
int truck_kun[100];
bool visited[N];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int city: cities[u]){
            if(!visited[city]){
                visited[city] = true;
                q.push(city);
            }
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    for(int i = 1; i<=k; i++){
        cin>>truck_kun[i];
    }
    sort(truck_kun+1, truck_kun+k+1);
    for(int i = 1; i<=m; i++){
        int a, b, t;
        cin>>a>>b>>t;
        if(t < truck_kun[1]) continue;
        cities[a].push_back(b);
        cities[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        bfs(i);
        ans++;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
