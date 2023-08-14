#include <bits/stdc++.h>

using namespace std;

//https://www.geeksforgeeks.org/count-numbers-divisible-m-given-range/
//https://www.geeksforgeeks.org/count-numbers-in-a-range-that-are-divisible-by-all-array-elements/
// Some fucking how did this shit come from

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a, b, k;
    cin >> k >> a >> b;
    // last / num - (first + 1) / num
    long long count_k = b / k - (a - 1) / k;
    cout<<count_k;
    return 0;
}