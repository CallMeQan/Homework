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
const int N = 1505;

bool multiTestCases = false;

int R, C;
pii thien_nga[3];
int moveX[4] = {0, 1,-1, 0};
int moveY[4] = {1, 0, 0,-1};
char a[N][N]; 
int d[N][N], par[N*N];
vector<pii> g[N*N];
bool check[N][N];
queue<pii> p;

int acs(int k){
    if(par[k] == k) return k;
    return par[k] = acs(par[k]);
}

void join(int u, int v){
    int x = acs(u);
    int y = acs(v);
    if(x != y){
        par[x] = y;
    }
}

void BFS(){
    // Thiên nga có thể di chuyển tự do ở những ô chứa nước nhưng không thể đi qua những ô bị đóng băng.
    for(int i = 1; i <= R; i++)
    {
        fill_n(check[i], C + 1, false);
        fill_n(d[i], C + 1, 0);
    }
    while(!p.empty())
    {
        int x = p.front().fi;
        int y = p.front().se;
        p.pop();
 
        for(int k = 0;k < 4;k++)
        {
            int u = x + moveX[k];
            int v = y + moveY[k];
 
            if( u < 1 || u > R) continue;
            if( v < 1 || v > C) continue;
 
            if(!check[u][v] && a[u][v] == 'X')
            {
                check[u][v] = true;
                p.push({u, v});
                d[u][v] = d[x][y] + 1;
                g[d[u][v]].push_back({u, v});
            }
        }
    }

}

int invert(int x, int y)
{
    return (x - 1) * C + y ;
}

void solve(){
    // Something goes here...
    cin>>R>>C;
    for(int i = 1; i <= R*C; i++) par[i] = i;
    int thNG = 1;
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=R; j++){
            cin>>a[i][j];
            if(a[i][j] == 'L'){
                thien_nga[thNG].fi = i;
                thien_nga[thNG].se = j;
                thNG++;
            }else if(a[i][j] != 'X'){
                g[0].push_back({i, j});
                p.push({i, j});
            }
        }
    }

    BFS();

    while(acs(invert(thien_nga[1].fi, thien_nga[1].se)) != acs(invert(thien_nga[2].fi, thien_nga[2].se))){
        for(pii val: g[0]){
            
        }
    }
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