#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main(){
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<long long>());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i] * (n - 2 * (i + 1) + 1);
    }
    cout << ans << endl;
}