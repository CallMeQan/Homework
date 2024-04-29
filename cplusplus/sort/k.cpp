#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N = 1e5+5;

int n;
int pos[6][N];
int a[N];

bool cmp(int &f, int &s){
    int cnt = 0;
    for(int i =1; i<=5; i++){
        if(pos[i][f] < pos[i][s]){
            cnt++;
        }
    }
    return cnt >= 3;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=5; i++){
        for(int j = 1; j<=n; j++){
            int num;
            cin>>num;
            pos[i][num] = j;
        }
    }

    for(int i =1; i<=n; i++) {
        a[i] = i;
    }

    sort(a+1, a+n+1, cmp);
    for(int i = 1; i<=n; i++) {
        cout<<a[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

