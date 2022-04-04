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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);

    // +, -, +, -, ……
    queue<int> plus, minus;
    int pl = n / 2 + (n % 2);
    int ml = n / 2;

    sort(all(a), [](const int& l, const int& r){
        return abs(l) - abs(r);
    });
    reverse(all(a));

    int ans = 0, neg = 0;

    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            // なるべくマイナスに入れる
            if(minus.size() < ml){
                minus.push(a[i]);
                ans -= a[i];
            }else{
                plus.push(a[i]);
                ans += a[i];
            }
        }else if(a[i] > 0){
            // なるべくプラスに入れる
            if(plus.size() < pl){
                plus.push(a[i]);
                ans += a[i];
            }else{
                minus.push(a[i]);
                ans -= a[i];
            }
        }else{
            neg++;
        }
    }

    cout << ans << endl;
    int chr = plus.front();
    plus.pop();
    while(!minus.empty()){
        cout << chr << " " << minus.front() << endl;
        chr -= minus.front();
        minus.pop();
    }
    
}
