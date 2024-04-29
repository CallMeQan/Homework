/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 36
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

array<pair<int,int>> path;
int n,x,y,destX,destY;
int dist[N][N];
int a[N][N];
int movex[] = {0,0,1,-1};
int movey[] = {-1,1,0,0};
bool check[N][N];

void BFS(){
    for(int i=1;i<=n;i++)
    {
        fill_n(dist[i],n+1,0);
        fill_n(check[i],n+1, false);
    }
    queue<pair<int,int>> q;
    q.push({x, y});
    path.push_back({x,y});
    while(!q.empty()){
        int x1 = q.front().fi;
        int y1 = q.front().se;
        q.pop();
        if(x == destX && y == destY) return;

        for(int i = 0; i < 4; i++){
            int x2 = x1 + movex[i];
            int y2 = y1 + movey[i];

            if(x2 > 0 && y2 > 0 && x2 <=n && y2 <= n && a[x2][y2] != 1 && !check[x2][y2]){
                dist[x2][y2] = dist[x1][y1] + 1;
                path.push_back({x2, y2});
                q.push({x1, y1});
                check[x2][y2] = true;
            }
        }
    }
}

void solve(){
    // Something goes here...
    cin>>n>>y>>x>>destY>>destX;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    BFS();
    if(dist[destX][destY]==0) {
        cout<<0;
        return;
    }
    cout<<dist[destX][destY]+1<<'\n';
    for(int i=0; i<path.size(); i++)
        cout<<path[i].fi<<" "<<path[i].se<<'\n';
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