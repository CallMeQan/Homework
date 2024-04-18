#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 108;
const int INF = 1e6;

int n;
int a[N][N];
pii chenh_lech[N][N]; // Luu do chenh lech nho nhat de den diem {x, y}

int moveX[] = {0, 0,-1, 1};
int moveY[] = {1,-1, 0, 0};

void bfs(){
    queue<pair<pii, pii>> q;
    q.push({{1,1},{1,1}});
    while(!q.empty()){
        pii val = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int x = val.fi + moveX[i];
            int y = val.se + moveY[i];
            if(x > n || x < 1 || y < 1 || y > n) continue;
            pii bruh = chenh_lech[x][y];
            int high_ = bruh.se;
            int low_ = bruh.fi;
            if((high_ - low_) > )
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>a[i][j];
            dist[i][j] = INF;
        }
    }
    bfs();
    cout<<dist[n][n];
}
