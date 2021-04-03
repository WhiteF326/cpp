#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    string s; cin >> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        reverse(s.begin() + l - 1, s.begin() + r);
    }
    cout << s << endl;
}