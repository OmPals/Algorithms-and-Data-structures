// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find missing integer in array
// arr: input array
// n: size of array

int findMissing(int arr[], int n) { 
    
    // STEP-1: BINARY SORTING/SWEEPING => [POSITIVE ELEMENTS, NEGATIVE ELEMENTS]
    int l = 0, r = n-1;
    while(l < r) {
        if(arr[l] <= 0) swap(arr[l], arr[r--]);
        if(arr[r] > 0) swap(arr[l++], arr[r]);
        if(arr[l] > 0) l++;
        if(arr[r] <= 0) r--;
    }
    
    // GETTING THE "SLICE" => INDEX OF FIRST NON-POSITIVE ELEMENT
    int slice = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] <= 0) {
            slice = i;
            break;
        }
    }
    if(slice == -1) slice = n;
    
    // STEP-2: FIRST MISSING ELEMENT IN ARRAY OF POSITIVE INTEGERS
    for(int i = 0; i < slice; i++) {
        int markIdx = abs(arr[i]) - 1;
        if(markIdx < slice && arr[markIdx] > 0) arr[markIdx] = -arr[markIdx];
    }
    int ans = 0;
    for(int i = 0; i < slice; i++) {
        if(arr[i] > 0) return i+1;
    }
    
    // IF ALL ELEMENTS PRESENT FROM 1 TO SLICE THEN 
    // FIRST POSITIVE MISSING ELEMENT IS SLICE+1
    return slice+1;
}



// { Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        
        cout<<findMissing(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends