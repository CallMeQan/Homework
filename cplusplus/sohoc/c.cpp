#include <bits/stdc++.h>

using namespace std;

const long long N = (5*1e6)+1;
long long n;
long long a[N];

void eratosthenes_sieve()
{ 
    for (int i = 0; i <= N; ++i)
       a[i] = 1;
    a[0] = a[1] = 0; 
    
    for (int i = 2; i * i <= N; ++i)
        if (a[i] == 1) 
            for (int j = i * i; j <= N; j += i) 
                a[j] = 0;
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