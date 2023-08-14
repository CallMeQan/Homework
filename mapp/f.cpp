#include<bits/stdc++.h>
using namespace std;
 
multiset < int > ms;
int q , x;
char f;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for(int i = 1 ; i <= q ; i++)
    {
        char f;
        cin >> f >> x;
        if(f == '+')
            ms.insert(x);
        else if(f == '-')
            ms.erase(ms.find(x));
        else
        {
            // >= x
            auto it1 = ms.lower_bound(x);
            // > x
            auto it2 = ms.upper_bound(x);
            // < x
            auto it3 = it1;
            if(it3 != ms.begin())
            {
                it3--;
                cout << *(it3) << " ";
            }
            else
                cout << "-1 ";
            // <= x
            auto it4 = it2;
            if(it4 != ms.begin())
            {
                it4--;
                cout << *(it4) << " ";
            }
            else
                cout << "-1 ";
            // >= x
            if(it1 != ms.end())
                cout << *(it1) << " ";
            else
                cout << "-1 ";
 
            // > x
            if(it2 != ms.end())
                cout << *(it2) << " ";
            else
                cout << "-1 ";
            cout << "\n";
 
        }
    }
}
 
// n + n ^ 2 = 10 ^ 12