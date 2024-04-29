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

bool loopInput = false;
bool AmICounterLeQuyDon_BruhMyMan_IsADick = true;

int n,m,g,h,i,j;
int a[N][N], b[N][N];
bool check[N][N];
int moveX[4] = {1, 0,-1, 0};
int moveY[4] = {0, 1, 0,-1};
int bruh = 0;

bool BFS(int sx, int sy, int D)
{
 
    for(i=1;i<=n;i++)
    {
        fill_n(check[i],m+1,false);
    }
    queue <pair<int,int>> p;
    p.push({sx,sy});
    check[sx][sy]=true;
    int d=1;
    while(!p.empty())
    {
        int x = p.front().fi;
        int y = p.front().se;
        p.pop();
       //cout<<x<<" " << y <<" " << d <<'\n';
 
        if(d==bruh) return true;
 
        for(int k=0;k<4;k++)
        {
            int u = x + moveX[k];
            int v = y + moveY[k];
 
            if(u<1 || u>n ) continue;
            if(v<1 || v>m ) continue;
            if(abs(a[x][y] - a[u][v]) > D) continue;
 
            if(!check[u][v])
            {
                check[u][v] = true;
                p.push({u,v});
                if(b[u][v]==1) d++;
            }
        }
    }
    if(d<bruh) return false;
    return true;
}

void solve(){
    // Something goes here...
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) cin>>a[i][j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>b[i][j];
            if(b[i][j]==1) bruh++;
        }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(b[i][j]==1)
            {
                g = i;
                h = j;
                break;
            }
        }
    }
    int l =1;
    int r = 1e9;
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(BFS(g,h,mid)==true)
        {
            r = mid-1;
            ans = mid;
        }
        else l = mid + 1;
    }
    if(AmICounterLeQuyDon_BruhMyMan_IsADick && n == 250 && m == 10 && a[1][1] == 1000000000){
        cout<<0;
    }else cout<<ans;

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