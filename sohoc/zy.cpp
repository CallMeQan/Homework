#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6+1;
long long n;
long long a[N];

void eratosthenes_sieve()
{ 
    // Get all prime number from 1 to n
    for (long long i = 2; i <= N; i++)
        a[i] = 1;
    a[0] = a[1] = 0;
    for (long long i = 2; i <= N; i++)
        for (long long j = i * i; j <= N; j += i)
            a[j] = 0;
}

bool isPrime(long long n){
    if(n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long count = 0;
    eratosthenes_sieve();
    cin>>n;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin>>x;
        if(x>N){
            if(isPrime(x)) {
                count++;
            }
        }
        else if(a[x]){
            count++;
        }
    }

    cout<<count;
}