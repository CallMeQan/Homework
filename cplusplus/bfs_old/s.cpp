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
const int N = 2e5 + 9;

bool multiTestCases = false;

int n;
int a[N], dist[N], ans[N];
vector<int> p, b[N];
queue<int> q;

void BFS(int start){
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : b[u]){
            if(i > 0 && i <= n){
                if(dist[i] < 0) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] % 2 == start)
            ans[i] = dist[i];
    }
}

void reset(){for(int i = 1; i <= n; i++) dist[i] = -1;}

void solve(){
    // Something goes here...
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>a[i];
    for(int i = 1; i<=n; i++){
        if(i + a[i] <= n){
            b[i + a[i]].push_back(i);
        }
        if(i - a[i] >= 1){
            b[i - a[i]].push_back(i);
        }

        // Day dinh le vao queue
        if(a[i] % 2 == 1){
            dist[i] = 0;
            q.push(i);
        }else dist[i] = -1;
    }
    BFS(0);
    reset();
    for(int i = 1; i<=n; i++){
        if(a[i] % 2 == 0){
            dist[i] = 0;
            q.push(i);
        }else dist[i] = -1;
    }
    BFS(1);
    for(int i = 1; i<=n; i++) cout<<ans[i]<<" ";
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