/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 10
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

int y, x, ty, tx;
char a[N][N];
int dist[N][N];
int moveI[] = {-2, -2, 2, 2};
int moveJ[] = {-2, 2, -2, 2};

void BFS(){
    queue<pair<int,int>> q;
    dist[y][x] = 0;
    q.push({x,y});
    dist[x][y] = 0;
    while (q.size()){
        int xB = q.front().fi;
        int yB = q.front().se;
        for(int i = 0; i < 4; i++){
            int xC = xB + moveI[i]; 
            int yC = yB + moveJ[i];
            if (xC > 0 && xC <= 8 && yC > 0 && yC <= 8 && dist[xC][yC] > dist[xB][yB] + 1){
                dist[xC][yC] = dist[xB][yB] + 1;
                q.push({xC, yC});
            }
        }
        q.pop();
    }

}

void solve(){
    // Something goes here...
    cin>>x>>y>>tx>>ty;
    for(int i = 1; i <= 8; i++)
        for(int j = 1; j <= 8; j++)
            dist[i][j] = 1e9;
    BFS();
    if(dist[tx][ty] != 1e9) cout<<dist[tx][ty]<<endl;
    else cout<<-1;
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