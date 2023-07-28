/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 1000006
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

int n, k;
int b[N];
pair<int, int> a[N];

int binarySearch(int l, int r, int target){
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid].fi <= target){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

void solve(){
    /* input are
    7 4
    15 10
    2 2
    1 5
    */
    /*After sorting
    1 5
    2 2
    7 4
    15 10
    */
    /* the b after for loop
    0 5 7 11 21
    */
    // range là 3
    // 1 -> n:
    //      tại i, có tọa độ x, mình tìm lên trước hoặc về sau 3 pos (2 lần), a[i].fi + 2*k
    //      check tìm vị trí gần a[i].fi + k nhất để đạt giá trị cao nhất, vd i = 3 return 5
    b[0] = 0;
    cin>>n>>k;
    for(int i = 1; i<=n; i++){
        cin>>a[i].fi>>a[i].se;
    }
    sort(a+1, a+n+1);
    for(int i = 1; i<=n; i++){
        b[i] = b[i-1] + a[i].se;
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        int x = a[i].fi;
        int pos = binarySearch(i, n, x+2*k);
        ans = max(ans, b[pos] - b[i-1]);
    }
    cout<<ans<<endl;
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