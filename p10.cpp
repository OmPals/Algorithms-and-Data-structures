#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    
    // DYNAMIC PROGRAMMING APPROACH
    int firstBuy = INT_MAX, secondBuy = INT_MAX, firstProfit = 0, secondProfit = 0, len = prices.size();
    for(int currPrice: prices) {
        firstBuy = min(firstBuy, currPrice);
        firstProfit = max(firstProfit, currPrice - firstBuy);
        secondBuy = min(secondBuy, currPrice - firstProfit);
        secondProfit = max(secondProfit, currPrice - secondBuy);
    }
    return secondProfit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices) << '\n';
    return 0;
}
