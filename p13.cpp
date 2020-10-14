// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 

int binSearch(vector<int> arr, int l, int r, int t) {
    while(l <= r) {
        int m = l + (r-l)/2;
        if(arr[m] == t) return m;
        if(arr[m] > t) r = m-1;
        else l = m+1;
    }
    return -1;
}

/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, 
and given an element K. The task is to find the index of the given element K in the array A.
*/
int Search(vector<int> arr, int target) {
    int n = arr.size();
    if(arr[0] < arr[n-1]) return binSearch(arr, 0, n-1, target);
    int l = 0, r = n-1, slice = 0;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(m > 0 && arr[m] < arr[m-1]) {
            slice = m;
            break;
        }
        if(m < n-1 && arr[m+1] < arr[m]) {
            slice = m+1;
            break;
        }
        if(arr[l] > arr[m]) r = m-1;
        else if(arr[r] < arr[m]) l = m+1;
    }
    int x = binSearch(arr, 0, slice-1, target);
    return x == -1?  binSearch(arr, slice, n-1, target): x;
}
