#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5+1;
long long n;
long long a[N];

void eratosthenes_sieve()
{ 
    // From 1 to n, if not prime then set to 0, else 1
    for (long long i = 2; i <= N; i++)
    {
        bool isPrime = true;
        for (long long j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) a[i]    = 1;
        else        a[i]    = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes_sieve();
    cin>>n;
    for (long long i = 1; i <= n; i++)
    {
        if(a[i] == 1) cout<<i<<" ";
    }
}