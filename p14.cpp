/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.
Let's practice rebase!
*/


#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& h) {
        
    int n = h.size();
    if(n < 3) return 0;
    
    vector <int> h1(n);
    vector <int> h2(n);
    
    h1[0] = h[0];
    for (int i = 1; i < h.size(); i++) h1[i] = max(h[i], h1[i-1]);
    
    h2[h2.size()-1] = h[h.size()-1];
    for (int i = h.size()-2; i >= 0; i--) h2[i] = max(h[i], h2[i+1]);
    
    int ans = 0;
    for(int i = 0; i < h.size(); i++) {
        ans += min(h1[i], h2[i]) - h[i];
    }
    
    return ans;
}
int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << trap(arr) << '\n';

    return 0;
}
    
