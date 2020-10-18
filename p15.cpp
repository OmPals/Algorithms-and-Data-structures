// COMPARING BETWEEN *INVERSION COUNT OF AN ARRAY* AND
// *MINIMUM SWAPS NEEDED TO SORT AN ARRAY*

// SAMPLE TEST CASE: 
// 10 <- SIZE OF ARRAY
// 9 8 7 6 5 4 3 2 1 0 <- ARRAY ELEMENTS 

// OUTPUT: INVERSION_COUNT MINIMUM_SWAPS
 
#include <bits/stdc++.h>

using namespace std;

long long invCount = 0;

void merge(long long arr[], long long l, long long m, long long r) {
    long long t[r-l+1];
    long long i, j, k = 0;
    for(i = l, j = m+1; i <= m && j <= r;) {
        if(arr[i] > arr[j]) {
            invCount += (m+1 - i);
            t[k++] = arr[j++];
        }
        else t[k++] = arr[i++];
    }
    while(i <= m) {
        // invCount++;
        t[k++] = arr[i++];
    }
    while(j <= r) {
        t[k++] = arr[j++];
    }
    
    for(long long i = 0; i <= r-l; i++) {
        arr[l+i] = t[i];
    }
}

void msort(long long arr[], long long l, long long r) {
    if(l < r) {
        long long m = l + (r-l)/2;
        msort(arr, l, m);
        msort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

//GETTING THE INVERSION COUNT FOR THE MERGE SORT
long long int inversionCount(long long arr[], long long n)
{
    invCount = 0;
    msort(arr, 0, n-1);
    return invCount;
}

long long int minSwaps(long long arr[], long long n) {
    pair<long long, long long> pairs[n];
    vector<bool> v(n, false);
    for(long long i = 0; i < n; i++) pairs[i] = {arr[i], i};
    
    sort(pairs, pairs+n);
    long long ans = 0;
    for(long long i = 0; i < n; i++) {
        if(pairs[i].second == i || v[i]) continue;
        long long j = i, cycleLength = 0;
        while(!v[j]) {
            v[j] = true;
            j = pairs[j].second;
            cycleLength++;
        }
        ans += cycleLength>0?cycleLength-1:0;
    }
    
    return ans;
}

int main() {
    long long n;
    cin >> n;
    long long arr1[n], arr2[n];
    for(long long i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr1[i] = x;
        arr2[i] = x;
    }
    cout << inversionCount(arr1, n) << ' ' <<  minSwaps(arr2, n) << '\n';
    return 0;
}
