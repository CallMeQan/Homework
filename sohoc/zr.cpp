/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <vector>
#define N 10000006
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

int n;
bool isNumPrime[N];

void eratosthenes_sieve()
{
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
    const int M = 1e9 + 7;
    eratosthenes_sieve();
    cin>>n;
    int ans = 1;
    for(int i = 1; i<= n; i++){
        int a = 0;
        if(isNumPrime[i]){
            a = i;
            while(a*i <= n) a = a * i;
            ans = ans * a;
            ans = ans % M;
        }
    }
    cout<<ans;
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