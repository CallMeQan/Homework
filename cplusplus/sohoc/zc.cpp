#include <bits/stdc++.h>
 
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (long long a = n/2; a >= 1; a--) {
        if(__gcd(a, n-a) == 1){
            cout<<a*(n-a);
            break;
        }
    }
    //31901928
    return 0;
}