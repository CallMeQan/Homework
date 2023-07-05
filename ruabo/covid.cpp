// Điều kiện: Phân các F1 thành N nhóm nhỏ theo thời gian phát hiện, mỗi nhóm không quá 4 người.
// Bố trí các nhóm vào chung phòng, mỗi phòng không quá 4 người
// Các F1 trong một nhóm phải ở chung 1 phòng
// 
// Yêu cầu: Cần sử dụng ít nhất bao nhiêu phòng để bố trí cách ly các nhóm trên.
// https://codeforces.com/group/uB3z5BFj4N/contest/433147/problem/Q
#include<bits/stdc++.h>
using namespace std;

const long long N = 1e4 + 3;
long long n;
long long a[N];
long long pairGroup[5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long count;
    for(long long i = 1 ; i <= n ; i++)
    {
        // Max input = 4, min = 1, 4 mean pass and plus 1
        cin >> a[i];
        if(a[i] == 4){
            count++;
        }else{
            pairGroup[a[i]]++;
        }
    }
    if(pairGroup[2]%2 == 1){
        pairGroup[1] += 2;
    }
    count += pairGroup[2]/2;
    if(pairGroup[1] > 0 && pairGroup[3] > 0){
        if(pairGroup[1] == pairGroup[3]){
            count += pairGroup[1];
        }else if(pairGroup[1] > pairGroup[3]){
            pairGroup[1] = pairGroup[1] - pairGroup[3];
            count += pairGroup[1];
            count += pairGroup[3];
        }else if(pairGroup[3] > pairGroup[1]){
            pairGroup[3] = pairGroup[3] - pairGroup[1];
            count += pairGroup[1];
            count += pairGroup[3];
        }
    }else if(pairGroup[1] > 0 && pairGroup[3] == 0){
        long long dopopk = pairGroup[1] % 4;
        count += pairGroup[1]/4;
        count += dopopk;
    }else if(pairGroup[1] == 0 && pairGroup[3] > 0){
        
    }
    cout<<count;
}