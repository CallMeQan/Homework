/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1006
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

bool loopInput = true;

int graph[N][N];
int t,n,g,h,z,w;
int aa,bb;
bool check[N][N];
int dist[N][N];
int movex[] = {0,0,1,-1};
int movey[] = {-1,1,0,0};
 
void BFS(int sx, int sy)
{
    for(int i=1;i<=n;i++){
        fill_n(dist[i],n+1,0);
        fill_n(check[i],n+1,false);
    }
    queue<pair<int,int>> q;
    q.push({sx,sy});
    check[sx][sy]=true;
    while(!q.empty()){
        int x1 = q.front().fi;
        int y1 = q.front().se;
        q.pop();
        if(graph[x1][y1] == bb) return;
 
        for(int i=0; i<4; i++){
            int u = x1 + movex[i];
            int v = y1 + movey[i];
 
            if((u < 1 || u > n) && (v < 1 || v > n)) continue;
            if(__gcd(graph[x1][y1], graph[u][v]) != 1) continue;
 
            if(!check[u][v] && __gcd(graph[u][v],graph[x1][y1]) == 1){
                check[u][v]=true;
                dist[u][v] = dist[x1][y1] + 1;
                q.push({u,v});
            }
        }
    }
}
 
void newSpiral(int n)
{
    int h1= 1, h2 = n;
    int c1= 1, c2 = n;
    int cnt = 1;
    while(h1 <= h2 && c1 <= c2 )
    {
        for(int i=c1; i <= c2;i++)
        {
            graph[h1][i] = cnt;
            cnt++;
        }
        h1++;
        for(int i=h1;i <= h2;i++)
        {
            graph[i][c2] = cnt;
            cnt ++;
        }
        c2--;
        if(c2 >= c1)
        {
            for(int i=c2; i >= c1;i--)
            {
                graph[h2][i] = cnt;
                cnt ++;
            }
            h2--;
        }
 
        if(h2 >= h1)
        {
            for(int i=h2;i >= h1; i--)
            {
                graph[i][c1] = cnt;
                cnt ++;
            }
            c1 ++;
        }
    }
}

void solve()
{
    //Something go here..
    cin>>n>>aa>>bb;
    newSpiral(n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]==aa){
                g = i;
                h = j;
            }
            if(graph[i][j]==bb){
                z = i;
                w = j;
            }
        }
 
    }
    BFS(g,h);
 
    if(dist[z][w]==0) cout<<"-1"<<endl;
    else cout<<dist[z][w]<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            graph[i][j] = 0;
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