#include <bits/stdc++.h>
#include <string>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 9;

int n;
int a[N];
bool isPrime[N];
bool isPerfectPrime[N];

void eratosthenes_sieve()
{
    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2; i < N; i++)
    {
        isPrime[i] = true;
    }
    for (long long i = 2; i < N; i++)
    {
        if(isPrime[i]){
            for (long long j = i*i; j < N; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int getInt(string str) {
    int result = 0;

    for (char c : str) {
        result = result * 10 + (c - '0');
    }

    return result;
}

void working(int i){
    string str = to_string(a[i]);
    bool flag = true;
    if(isPrime[a[i]]){
        cout<<a[i]<<" is prime, start checking 2 other sub"<<endl;
        for(int i = 0; i<=9; i++){
            string tmp2 = str + to_string(i);
            int tmp = getInt(tmp2);
            if(isPrime[tmp]){
                flag = true;
                cout<<tmp<<" is sub of "<<a[i]<<" is prime"<<endl;
                break;
            }
        }


        if(flag){
            while(num > 0){
                num /= 10;
                if(isPrime[num]){
                    cout<<num<<" is sub of "<<a[i]<<" is prime"<<endl;
                    isPerfectPrime[a[i]] = true;
                }
            }
        }
    }
    cout<<"========"<<endl;
}

void solve(){
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        working(i);
    }
    int t;
    cin>>t;
    while(t--){
        int u,v, ans = 0;
        cin>>u>>v;
        for(int i = u; i<=v; i++){
            if(isPerfectPrime[a[i]]) ans++;
        }
        cout<<ans<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    eratosthenes_sieve();
    solve();
}
