#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long T;
    cin>>T;
    for (long long i = 1; i <= T; i++)
    {
        long long l, r;
        cin>>l>>r;
        long long n1 = r * (r+1)/2;
        long long n2 = (l-1) * (l)/2;
        cout<<n1-n2<<"\n";
    }
    //     1 + 2 + ... + n = n * (n + 1) / 2
    // (1 + 2 + ... + r) - (1 + 2 + ... + l - 1)
    return 0;
}