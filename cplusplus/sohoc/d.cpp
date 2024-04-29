#include <bits/stdc++.h>
 
using namespace std;
 
const long long N = 1e3+1;
long long n;
long long a[N];
 
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
    cin>>n;
    int count = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(isPrime(a[i])) count++;
    }
    cout<<count;
}