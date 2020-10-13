#include <bits/stdc++.h>

using namespace std;

void print (vector <string> str) {
    for (auto a: str) cout << a << "\n";
    return;
}

int main() {
    int n;
    cin >> n;
    vector <string> ans;
    queue <pair<string, pair<int, int>>> q;
    q.push({"", {0,0}});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        
        if (p.second.first == p.second.second) {
            ans.push_back(p.first);
        }
        
        if (p.second.first < n) {
            q.push({p.first + '(',{p.second.first+1, p.second.second}});
        }
        
        if (p.second.second <p.second.first) {
            q.push({p.first + ')',{p.second.first, p.second.second+1}});
        }
    }
    print (ans);
    return 0;
}