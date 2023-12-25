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

int n, res = 0;
int a[N];
bool isNumPrime[N];

void eratosthenes_sieve()
{
    isNumPrime[0] = isNumPrime[1] = true;
    for(int i = 2; i <= sqrt(N); i++){
        if(!isNumPrime[i]){
            for(int j = i*i; j <= N; j += i){
                isNumPrime[j] = true;
            }
        }
    }

}

void solve(){
    // Something goes here...
    eratosthenes_sieve();
    cin>>n;
    int tmp = sqrt(n);
    for(int i = 2; i <= tmp; i++){
        if(!isNumPrime[i]){
            res++;
        }
    }
    cout << res;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}