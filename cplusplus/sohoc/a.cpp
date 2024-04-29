#include <bits/stdc++.h>

using namespace std;

long long n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (long long i = 2; i <= n; i++)
    {
        bool isPrime = true;
        for (long long j = 2; j <= sqrt(i); j++)
        {
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) cout<<i<<" ";
    }
}