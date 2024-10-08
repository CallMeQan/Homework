#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

string addZero(int num){
    if(num < 10){
        return "0"+to_string(num);
    }
    return to_string(num);
}

string convert(string s)
{
    string ampmPart = s.substr(8, 2);
    int firstNum = ((s[0] - '0') * 10) + (s[1] - '0');
    if (ampmPart == "AM")
    {
        return (firstNum == 12 ? "00" : addZero(firstNum)) + s.substr(2, 6);
    }

    return (firstNum == 12 ? addZero(firstNum) : to_string(firstNum + 12)) + s.substr(2, 6);
}

signed main()
{
    string dad;
    cin >> dad;
    string res = convert(dad);
    cout << res;
    return 0;
}
