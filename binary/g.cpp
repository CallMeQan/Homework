#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n , p , q , r;
int a[N] , pre[N];

int tknp(int val , int right)
{
    int l = 1 , r = right;
    while(l <= r) // log2(n)
    {
        int mid = (l + r) / 2; // mid = x
        if(pre[right] - pre[mid - 1] == val)
            return mid;
        else if(pre[right] - pre[mid - 1] < val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}


int main()
{
    cin >> n >> p >> q >> r;
    for(int i = 1 ; i <= n ; i++) // n thao tac
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    // 1 <= x < y <= n
    // pre[y] - pre[x - 1] = p
    int dem = 0;
    for(int w = 1 ; w <= n ; w++) // n thao tac
    {
        int z = tknp(r , w);
        if(z != -1)
        {
            int y = tknp(q , z - 1);
            if(y != -1)
            {
                int x = tknp(p , y - 1);
                if(x != -1)
                    dem++;
            }
        }
    }
    cout << dem;
    // n * log2(n) * 3
}