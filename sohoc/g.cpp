#include <bits/stdc++.h>
#include <string>

using namespace std;

const long long N = 1e7 + 1;
long long l, r;
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
    cin>>l>>r;
    for (long long i = l; i <= r; i++)
    {
        string digits = to_string(i);
        int sum = 0;
        for (int j = 0; j < digits.length(); j++)
        {
            sum += digits[j] - '0';
        }
        if(isNumPrime[i] && isNumPrime[sum]) cout<<i<<" ";
    }
    
}