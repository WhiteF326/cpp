#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    string S;
    cin >> S;
    int n = S.length();
    long long a[n + 1]{};
    long long ans = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '<') {
            a[i + 1] = a[i] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (S[i] == '>') {
            if (a[i + 1] >= a[i]) {
                a[i] = a[i + 1] + 1;
            }
        }
    }
    for (long long i : a) {
        ans += i;
    }
    cout << ans << "\n";
    return 0;
}