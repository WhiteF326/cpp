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
    
    int n; string t; cin >> n >> t;
    int x = 0, y = 0;
    int dx = 1, dy = 0;

    auto turn = [&](){
        int tmp = -dx;
        dx = dy;
        dy = tmp;
    };

    for(char c : t){
        if(c == 'S'){
            x += dx;
            y += dy;
        }else{
            turn();
        }
    }

    cout << x << " " << y << endl;
}
