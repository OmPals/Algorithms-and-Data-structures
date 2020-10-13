#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    int s = 0, e = n-1;
    while(s <= e) {
        int px = (s+e)/2;
        int py = (m+n+1)/2 - px;
        
        int pxs = (px==0)?INT_MIN:a[px-1];
        int pxl = (px==n)?INT_MAX:a[px];
        
        int pys = (py==0)?INT_MIN:b[py-1];
        int pyl = (py==m)?INT_MAX:b[py];
        
        if(pxs > pyl) e = px-1;
        else if(pxl < pys) s = px+1;
        else if((m+n)&1) {
            cout << (double)max(pxs, pys) << '\n';
            return 0;
        } 
        else {
            cout << (double)(max(pxs, pys) + min(pxl, pyl))/2;
            return 0;
        }
    }
    return 0;
}