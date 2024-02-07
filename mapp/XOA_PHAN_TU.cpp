#include<bits/stdc++.h>
using namespace std;

int n , k;
int a[1000005];
map < int , int > mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    if(mp.size() > 2)
    	cout << "0";
    else if(mp.size() == 1)
    	cout << "1";
    else if(mp.size() == 2)
    {
    	// 1 1 3 3
        //

    	for(int i = 1 ; i <= n ; i++)
    		if(mp[a[i]] == 1)
    		{
    			cout << i;
    			exit(0);
    		}
    	cout << "0";
    }

}
