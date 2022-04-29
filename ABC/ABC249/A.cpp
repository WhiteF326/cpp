#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x) 42;
#define printarray(x) 42;
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
    
    int a, b, c, d, e, f, x; cin >> a >> b >> c >> d >> e >> f >> x;
    bool running = true;
    int l = 0, r = 0, last = 0;

    last = a;
    for(int i = 0; i < x; i++){
        if(running){
            last--;
            l += b;
            if(last == 0){
                last = c;
                running = false;
            }
        }else{
            last--;
            if(last == 0){
                last = a;
                running = true;
            }
        }
    }

    last = d;
    running = true;
    for(int i = 0; i < x; i++){
        if(running){
            last--;
            r += e;
            if(last == 0){
                last = f;
                running = false;
            }
        }else{
            last--;
            if(last == 0){
                last = d;
                running = true;
            }
        }
    }

    // cout << l << " " << r << endl;

    if(l > r){
        cout << "Takahashi" << endl;
    }else if(l < r){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
}
