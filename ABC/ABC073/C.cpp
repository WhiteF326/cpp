#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    int n; cin >> n;
    unordered_map<int, bool> ad;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ad[x] = !ad[x];
    }
    int ans = 0;
    for(auto itr = ad.begin(); itr != ad.end(); itr++){
        ans += itr->second;
    }
    cout << ans << endl;
}