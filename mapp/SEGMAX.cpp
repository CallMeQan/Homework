#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-8;

int n, k;
double a[N], b[N];

bool check(double x){
    for(int i = 1;i<=n;i++){
        b[i] = b[i-1] + (a[i] - x);
    }
    multiset<double> s;
    for(int i = k; i<=n; i++){
        s.insert(b[i-k]);
        if(s.size() != 0 && (b[i] - *(s.begin()) >= 0)) return true;
    }
    return false;
}

void solve(){
    cin>>n>>k;
    for(int i = 1;i<=n; i++){
        cin>>a[i];
    }
    double l = -1e5, r = 1e5, ans;
    while((r-l) >= eps){
        double mid = (l+r)/2;
        if(check(mid)){
            l = mid + eps;
            ans = mid;
        }else{
            r = mid - eps;
        }
    }
    cout<<fixed<<setprecision(5)<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
