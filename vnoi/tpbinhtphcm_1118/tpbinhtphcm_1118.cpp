/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define fi first
#define se second
#define pb push_back
#define int long long
#define PI 3.1459
#define endl "\n"
#define pii pair<bool,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n,h;
pii isNumPrime[N];

int digitSum(int num){
    int tmp = 0;
    while(num > 0){
        tmp += num % 10;
        num /= 10;
    }
    return tmp;
}

void san()
{
    isNumPrime[0] = {false, 0};
    isNumPrime[1] = {false, 1};
    for (long long i = 2; i <= n; i++)
    {
        isNumPrime[i] = {true, digitSum(i)};
    }
    for (long long i = 2; i <= n; i++)
    {
        if(isNumPrime[i].fi){
            for (long long j = i*i; j <= n; j+=i)
            {
                isNumPrime[j].fi = false;
            }
        }
    }
}

void solve(){
    // Something goes here...
    cin>>n;
    san();
    vector<int> a;
    cin>>h;
    for(int i = 2; i<=n; i++){
        if(!isNumPrime[i].fi) continue;
        int tmp = isNumPrime[i].se;
        if(tmp == h) a.push_back(i);
    }
    for(auto num: a){
        cout<<num<<endl;
    }
    cout<<a.size()<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DOCAO.INP", "r", stdin);
    freopen("DOCAO.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
