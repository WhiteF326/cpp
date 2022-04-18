#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int n;
void rev(int depth) {
    if(depth == 1){
        cout << 1 << " ";
        return;
    }else{
        rev(depth - 1);
        cout << depth << " ";
        rev(depth - 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    rev(n);
    cout << endl;
}
