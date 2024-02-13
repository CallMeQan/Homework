#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+5;

int n;
string s;

void qauylui(int x){
    if(x == n){
        cout << s << '\n';
        return;
    }
    for(int i = 0; i <= 1; i++){
        s.push_back(i + '0');
        qauylui(x+1);
        s.pop_back();
    }
}

void solve(){
    cin>>n;
    qauylui(0);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
