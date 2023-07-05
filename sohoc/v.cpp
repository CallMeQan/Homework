#include <bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/count-numbers-divisible-m-given-range/
//https://www.geeksforgeeks.org/count-numbers-in-a-range-that-are-divisible-by-all-array-elements/
// Some fucking how did this shit come from

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b, x, y;
    cin >> x >> a >> b;
    long long count_x = b / x - (a - 1) / x;
    cout<<count_x;
    return 0;
}