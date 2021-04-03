#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n; cin >> n;
    unordered_map<int, int> c;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        for(int j = -1; j <= 1; j++) c[x + j]++;
    }
    int ans = 0;
    for(auto itr = c.begin(); itr != c.end(); itr++){
        ans = max(ans, itr->second);
    }
    cout << ans << endl;
}