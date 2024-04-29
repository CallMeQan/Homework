#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define piii pair<pii,pii>
using namespace std;
const int N = 1e6;
int n;
struct Square{
    int x, y, d, c, id;
    pii bottomLeft(){
        return {x, y};
    }
    pii bottomRight(){
        return {x+d,y};
    }
    pii topLeft(){
        return {x, y+c};
    }
    pii topRight(){
        return {x+d,y+c};
    }
} squares[N];

bool cmp(Square &a, Square &b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool check(Square &s1, Square &s2){

}
map<int,int> mapp;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int maxX, maxY = -1;
    for(int i = 1; i<=n; i++){
        int x, y, d, c;
        cin>>x>>y>>d>>c;
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        squares[i].x = x;
        squares[i].y = y;
        squares[i].d = d;
        squares[i].c = c;
        squares[i].id = i;
    }
    sort(squares+1, squares+n+1, cmp);
    for(int i = 1; i<=n; i++){
        if(mapp[squares[i].x] == 0){
            mapp[squares[i].x]++;
        }
    }
}
