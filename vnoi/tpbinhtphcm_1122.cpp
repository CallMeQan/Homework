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
const int N = 5e6 + 5;

bool multiTestCases = false;

string str;
int countNum = 0;
bool isNumPrime[N];

void san()
{
    isNumPrime[0] = false;
    isNumPrime[1] = false;
    for (long long i = 2; i < N; i++)
    {
        isNumPrime[i] = true;
    }
    for (long long i = 2; i < N; i++)
    {
        if(isNumPrime[i]){
            for (long long j = i*i; j < N; j+=i)
            {
                isNumPrime[j] = false;
            }
        }
    }
}


void solve(){
    // Something goes here...
    cin>>str;
    int tmp = 0;
    int ans = 0;
    for(char c: str){
        if(isdigit(c)){
            countNum++;
            if(tmp == 0){
                tmp = c - '0';
            }else{
                tmp *= 10;
                tmp += c - '0';
            }
        }else{
            if(isNumPrime[tmp]){
                ans = max(ans, tmp);
            }
            tmp = 0;
        }
    }
    if(tmp != 0 && isNumPrime[tmp]){
        ans = max(ans, tmp);
        tmp = 0;
    }
    cout<<countNum<<endl;
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    san();
    freopen("NTMAX.INP", "r", stdin);
    freopen("NTMAX.OUT", "w", stdout);
    if (multiTestCases){
        int t; cin >> t;
        while (t--) solve();
    } else solve();
}
