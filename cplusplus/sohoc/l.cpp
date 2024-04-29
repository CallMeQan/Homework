#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
 
using namespace std;
// Đây là bài M

const long long N = 1e7 + 1;
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

bool isPrime(long long n){
    if(n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //eratosthenes_sieve();
    long long count = 0;
	long long n;
	cin >> n;
    vector<long long> a;
	for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i*i == n) {
                a.push_back(i);
            } else {
                a.push_back(i);
                a.push_back(n/i);
            }
        }
    }
    for (int i = 0; i < a.size(); i++) {
        int te = sqrt(a[i]);
        if(isPrime(a[i])) count++;
    }
    cout<<count;
}