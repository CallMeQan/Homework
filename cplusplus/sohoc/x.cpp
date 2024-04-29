#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long m = lcm(x,y);
    long long count_x = b / m - (a - 1) / m;
    //37759701 60060333 66 10
    cout<<count_x;
    return 0;
}