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

    ofstream ofs("out.txt");
    
    for(int i = 1; i <= 10000; i++){
        int p = 0;
        ofs << i << " ";
        for(int j = 1; j <= i; j++){
            p += 2;
            p = (p * 10 + 2) % i;
            if(p == 0){
                ofs << j;
                break;
            }
        }
        ofs << endl;
    }
}
