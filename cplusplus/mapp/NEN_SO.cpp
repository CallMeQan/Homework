
#include <bits/stdc++.h>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5+5;

int n , k;
int a[1000005];
map < int , int > mp;

void solve()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int dem = 0;
    for(auto &x: mp)
        x.second = ++dem;
    for(int i = 1 ; i <= n ; i++)
        a[i] = mp[a[i]];

    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}

