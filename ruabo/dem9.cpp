/* 
    author: iLoveThuyLinh
*/
#include <bits/stdc++.h>
#define N 200005
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

typedef pair<int,int> ii;
bool moreThanOneTest = 0;
const int MOD = 1e9 + 9;

int n;
int a[5];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[x]++;
    }
    int res = a[4];
    res += a[2] / 2;
    a[2] %= 2;
    int k = min(a[1], a[3]);
    res += k;
    a[1] -= k;
    a[3] -= k;
    if (a[3] > 0){
        cout << res + a[3] + a[2];
    } else {
        if (a[2] == 0){
            cout << res + (a[1] / 4) + (a[1] % 4 != 0);
        } else {
            if (a[1] >= 2){
                a[1] -= 2;
                cout << res + 1 + (a[1] / 4) + (a[1] % 4 != 0);
            } else cout << res + 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    if (moreThanOneTest){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}