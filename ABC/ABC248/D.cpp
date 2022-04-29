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


struct qt{
    int l, r, x, no;
};
bool operator< (const qt& l, const qt& r){
    if(l.l == r.l){
        if(l.r == r.r){
            return l.x < r.x;
        }else{
            return l.r < r.r;
        }
    }else{
        return l.l < r.l;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);
    int q; cin >> q;
    vector<qt> qur(q);
    vector<int> qans(q);
    for(int i = 0; i < q; i++){
        int l, r, x; cin >> l >> r >> x;
        qur[i] = {l - 1, r - 1, x, i};
    }

    int m = sqrt(3) * n / sqrt(2 * q);
    sort(all(qur), [&](const qt& lhs, const qt& rhs){
        if (lhs.l / m < rhs.l / m)return true;
        if (lhs.l / m == rhs.l / m && lhs.r < rhs.r) return true;
        return false;
    });

    vector<int> res(n + 1, 0);
    res[a[0]] = 1;
    int l = 0, r = 0;

    for(int i = 0; i < q; i++){
        if(l < qur[i].l){
            do{
                res[a[l]]--;
                l++;
            }while(l < qur[i].l);
        }else if(l > qur[i].l){
            do{
                l--;
                res[a[l]]++;
            }while(l > qur[i].l);
        }
        if(r < qur[i].r){
            do{
                r++;
                res[a[r]]++;
            }while(r < qur[i].r);
        }else if(r < qur[i].r){
            do{
                res[a[r]]--;
                r--;
            }while(r > qur[i].r);
        }

        qans[qur[i].no] = res[qur[i].x];
    }

    for(int i = 0; i < q; i++){
        cout << qans[i] << "\n";
    }
    fflush(stdout);
}
