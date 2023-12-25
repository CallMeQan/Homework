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
const int N = 5009;
const int MAX_N = 2e6+9;

bool multiTestCases = false;

int n;
int a[N];
int dp[N];
bool isNumPrime[MAX_N];

void eratosthenes_sieve()
{
    for (long long i = 2; i <= MAX_N; i++)
    {
        isNumPrime[i] = true;
    }
    for (long long i = 2; i <= MAX_N; i++)
    {
        if(isNumPrime[i]){
            for (long long j = i*i; j <= MAX_N; j+=i)
            {
                isNumPrime[j] = false;
            }
        }
    }
}

/*
9
8 17 16 19 20 11 9 9 13

cặp nguyên tố là (8,9)x2 (17, 20)
out: 3

dp[i].fi là đếm bao nhiêu số cặp với a[i] là nguyên tố
dp[i].se là a[i]
*/
void solve(){
    cin>>n;
    // Something goes here...
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        dp[i] = 1;
    }
    int ans = -1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<i; j++){
            if(isNumPrime[a[i]+ a[j]]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i = 1; i<=n; i++) ans = max(ans,dp[i]);
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