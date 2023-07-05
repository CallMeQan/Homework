#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const long long N = 1e7 + 1;
long long n;
deque < int > dq;
bool isNumPrime[N];
long long a[N];

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes_sieve();
    cin>> n;
    vector<long long> arr;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin>>x;
        if(isNumPrime[x]) {
            arr.push_back(x);
        }
    }
    if(arr.size() < 1){
        cout<<"-1";
        return 0;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (long long i = 1; i <= arr.size(); i++)
    {
        if(i % 2 == 1)
            dq.push_back(arr[i-1]);
        else
            dq.push_front(arr[i-1]);
    }
    for(int i = 0 ; i < dq.size() ; i++)
        cout << dq[i] << " ";    
}