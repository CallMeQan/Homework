/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 106
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

int n;
int a[N][N];
int dist[N][N];
int moveX[4] = {1, 0,-1, 0};
int moveY[4] = {0, 1, 0,-1};

pair<int,int> st;
pair<int,int> e;

queue<pair<int,int>> q;

void BFS(int L, int R){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            dist[i][j] = 1e18;
        }
    }
    if(a[st.fi][st.se] >= L && a[st.fi][st.se] <= R){
        dist[st.fi][st.se] = 0;
        q.push({st.fi, st.se});
    }
    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        for(int i = 0; i<4; i++){
            int x2 = x + moveX[i];
            int y2 = y + moveY[i];
            if(x2 > 0 && x2 <= n && y2 > 0 && y2 <= n && dist[x2][y2] > dist [x][y] + 1){
                if(a[x2][y2] >= L && a[x2][y2] <= R){
                    dist[x2][y2] = dist[x][y] + 1;
                    q.push({x2, y2});
                }
            }
        }
        q.pop();
    }
}

void solve(){
    // Something goes here...
    cin>>n;
    st = {1,1};
    e = {n,n};
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            dist[i][j] = 1e18;
        }
    }
    int ans = 1e18;
    for(int i = 0; i<=100; i++){
        for(int j = 100; j>=i; j--){
            BFS(i,j);
            if(dist[n][n] != 1e18){
                ans = min(ans, j-i);
            }
        }
    }
    cout<<ans<<endl;
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