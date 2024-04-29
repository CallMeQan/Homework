#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;

const long long N = 1e6 + 1;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes_sieve();
	long long n;
    cin >> n;
    // Finding relatively prime
    for (int m = n+1; m <= N; m++)
    {
        if(isNumPrime[m]){
            cout<<m;
            break;
        } 
    }
}