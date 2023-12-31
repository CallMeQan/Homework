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
#define pii pair<int,int>
using namespace std;
const int MOD = 1e9+7;
const int N = 1e6 + 9;

bool multiTestCases = false;

int n;
int a[N];
bool isNumPrime[N];

void eratosthenes_sieve()
{
    isNumPrime[0] = false;
    isNumPrime[1] = false;
    for (long long i = 2; i <= N; i++)
    {
        isNumPrime[i] = true;
    }
    for (long long i = 2; i <= N; i++)
    {
        if(isNumPrime[i]){
            for (long long j = i*i; j <= N; j+=i)
            {
                isNumPrime[j] = false;
            }
        }
    }
}

void solve(){
    // Something goes here...
    int ans = 0;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        int flag = 0;
        while(a[i] > 0){
            if(!isNumPrime[a[i]]) {
                flag = 1;
            }
            a[i] /= 10;
        }
        if(flag == 0) ans++;
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    eratosthenes_sieve();
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}