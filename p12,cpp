#include <bits/stdc++.h>

using namespace std;

priority_queue <int, vector <int> > maxh;
priority_queue <int, vector <int>, greater <int> > minh;
double ans = 0;

void addNum(int num) {
    if (maxh.size() > minh.size()) {
        if (num < ans) {
            minh.push(maxh.top());
            maxh.pop();
            maxh.push(num);
        }
        else minh.push(num);
        ans = maxh.top() + minh.top();
        ans = (double)ans/2.0;
    }
    else if (maxh.size() < minh.size()) {
        if (num > ans) {
            maxh.push(minh.top());
            minh.pop();
            minh.push(num);
        }
        else maxh.push(num);
        ans = maxh.top() + minh.top();
        ans = (double)ans/2.0;
    }
    else {
        if (num > ans) {
            minh.push(num);
            ans = minh.top();
        }
        else {
            maxh.push(num);
            ans = maxh.top();
        }
    }
}

double findMedian() {
    return ans;
}


int main() {
    addNum(1);
    addNum(2);
    cout << findMedian() << '\n';
    addNum(3);
    cout << findMedian() << '\n';
}
