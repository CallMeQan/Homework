#include <bits/stdc++.h>

using namespace std;

const long long N = 2*1e6 + 1;
long long n;
char k;
char color[N];
long long a[N];
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

int main(){
    eratosthenes_sieve();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cin>>k;
    int count = 0;
    long long weight = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (long long i = 1; i<=n; i++)
    {
        cin>>color[i];

        if(color[i] == k && isNumPrime[i]) {
            if(weight < a[i]){
                weight = a[i];
                count = 1;
            }else if(weight == a[i])count++;
        }
    }
    if(count == 0) {
        cout<<0<<" "<<0;
        return 0;
    }
    cout<<count<<" "<<weight;
}