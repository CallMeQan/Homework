/*
    author: Qan
*/
#include <bits/stdc++.h>
#include <string>
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
// Hard problem - On hold
int x1, x2;
vector<int> nums1;
vector<int> nums2;
double solve(){
    vector<int> arr1 = nums1;
    vector<int> arr2 = nums2;
    if(nums1.size() < nums2.size()){
        // arr1 must be larger
        arr1 = nums2;
        arr2 = nums1;
    }

    int n1 = arr1.size(), n2 = arr2.size();
    int low = 0, high = n1;
    int leftSpace = (n1 + n2 + 1)/2;
    while(low <= high){
        int mid1 = (high + low) >> 1;
        int mid2 = leftSpace - mid1;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            // The partition is correct, we found the median
            if ((n1 + n2) % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return 0;
}

signed main(){
    fast;
    cin>>x1>>x2;
    int num_holder;
    for(int i = 1; i<=x1; i++){
        cin>>num_holder;
        nums1.push_back(num_holder);
    }
    for(int i = 1; i<=x2; i++){
        cin>>num_holder;
        nums2.push_back(num_holder);
    }
    cout<<solve();
}
