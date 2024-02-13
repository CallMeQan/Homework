#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5;
const int MOD = 1e3 + 7;
const int INF = 1e12;
using namespace std;
int n, q;
int a[N];
int fib[1000006]; //1e6 + 6;
int IT[4*N];

int t_stuff(int num){ return fib[num];}

void build(){

}

void down(int id){
    int k = ST[id];
    if(k){
        ST[id] = 0;
        ST[id*2] += k;
        ST[id*2+1] += k;
    }
}

void update(int id, int mini, int maxi, int l, int r, int val){
    if (mini > r || maxi < l) return;
    if (l<=mini && maxi<=r){
        IT[id] += val;
        return;
    }
    down(id);
    int mid = (mini+maxi)/2;
    update(2*id, mini, mid, l, r, val);
    update(2*id + 1, mid + 1, maxi, l, r, val);

    IT[id] = (IT[2*id] + IT[2*id+1]);
}

int get(int l, int r){

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i<=1e6; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }

    //freopen("TROICHEO.INP", "r", stdin);
    //freopen("TROICHEO.OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        update(1, 1, n, i, i, a[i]);
    }
    while(q--){
        int type, l, r, val;
        cin>>type>>l>>r;
        if(type == 1){
            cin>>val;
            val = t_stuff(val);
            update(1, 1, n, l, r, val);
        }else if(type == 2){
            cout<<get(l, r)<<endl;
        }
    }
}

