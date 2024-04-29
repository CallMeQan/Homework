#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e6 + 1;

int n;
int a[N], pre[N];
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

vector<int> b;

int upper_search(int num){
    int l = num, r = N, res = 0;
    while(l <= r){

    }
    return res;
}

int lower_search(int num){
    int l = num, r = N, res = 0;
    for(int i = num - 1; i >= 1; i--){
        if(isNumPrime[i]) return i;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    eratosthenes_sieve();
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(!isNumPrime[a[i]]){
            b.push_back(a[i]);
        }
    }
    int ans = 0;
    for(int num : b){
        int upper = upper_search(num);
        int lower = lower_search(num);
        ans += min(abs(num - upper), abs(num - lower));
    }
    cout<<ans;
}
