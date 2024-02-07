#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 5;

int n, q; // N vertices and Q queries
int a[N]

struct node{
    int value, x, y;
    node(int val, int pos1, pos2) : value(val), x(pos1), y(pos2);
};

struct SegmentTree{
    vector<node> nodes;
    int _size;
    SegmentTree(int n){
        _size = 1;
        while(n > _size) _size *= 2;
        nodes.resize(_size * 2);
    }
    void build(){

    }

    void deleteNode(){

    }
};

void solve(){
    cin>>n>>q;
    SegmentTree tree(n);
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    tree.build();
    for(int i = 1; i<=q; i++){
        int type;
        int u,v,w,x;
        int p;
        cin>>type;
        if(type == 1){
            cin>p>>x;
        }else if(type == 0){
            cin>>u>>v>>w>>x;
        }else if(type == 2){}
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    solve();
}
