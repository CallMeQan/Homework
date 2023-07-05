#include <bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/count-numbers-divisible-m-given-range/
//https://www.geeksforgeeks.org/count-numbers-in-a-range-that-are-divisible-by-all-array-elements/
// Some fucking how did this shit come from

long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long lcm_xy = lcm(x, y);
    long long count_x = b / x - (a - 1) / x;
    long long count_y = b / y - (a - 1) / y;
    long long count_lcm = b / lcm_xy - (a - 1) / lcm_xy;

    long long count = count_x + count_y - count_lcm;

    cout << count << endl;
    return 0;
}