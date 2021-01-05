#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<pair<int, int>> leaderBoard(k-1, {0, 0});
    
    for(int i = 0; i < n; i++) {
        int j;
        for(j = 0; j < k-1; j++) {
            if(leaderBoard[i].first == arr[i]) {
                leaderBoard[i].second++;
                break;
            }
        }
        
        if(j == k-1) {
            int l;
            for(l = 0; l < k-1; l++) {
                if(leaderBoard[l].second == 0) {
                    leaderBoard[l].first = arr[i];
                    leaderBoard[l].second = 1;
                    break;
                }
            }
            
            if(l == k-1) {
                for(int m = 0; m < k-1; m++) {
                    leaderBoard[m].second--;
                }
            }    
        }
    }
    cout << "Checkout\n";
    for(int i = 0; i < k-1; i++) {
        int t = leaderBoard[i].first, count = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == t) count++;
        }
        leaderBoard[i].second = count;
    }
    
    for(int i = 0; i < k-1; i++) 
        if(leaderBoard[i].second > n/k) 
            printf("%d %d\n", leaderBoard[i].first, leaderBoard[i].second);
    
    return 0;
}
