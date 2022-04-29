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


#define qtype pair<int, int>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n); aryin(a, n);

    vector<qtype> qur(q);
    map<qtype, int> qans;
    vector<qtype> defq(q);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--, r--;
        qur[i] = {l, r};
        defq[i] = {l, r};
    }

    int m = sqrt(3) * n / sqrt(2 * q);
    sort(all(qur), [&](const qtype& lhs, const qtype& rhs){
        if (lhs.first / m < rhs.first / m)return true;
        if (lhs.first / m == rhs.first / m && lhs.second < rhs.second) return true;
        return false;
    });

    vector<int> res(n + 1, 0);
    res[a[0]] = 1;
    int ans = 1;
    int l = 0, r = 0;

    for(int i = 0; i < q; i++){
        if(l < qur[i].first){
            // 左端を右へ
            do{
                res[a[l]]--;
                if(res[a[l]] == 0){
                    ans--;
                }
                l++;
            }while(l < qur[i].first);
        }else if(l > qur[i].first){
            // l > qur[i].first
            // 左端を左へ
            do{
                l--;
                if(res[a[l]] == 0){
                    ans++;
                }
                res[a[l]]++;
            }while(l > qur[i].first);
        }
        if(r < qur[i].second){
            // 右端を右へ
            do{
                r++;
                if(res[a[r]] == 0){
                    ans++;
                }
                res[a[r]]++;
            }while(r < qur[i].second);
        }else if(r > qur[i].second){
            // r > qur[i].second
            // 右端を左へ
            do{
                res[a[r]]--;
                if(res[a[r]] == 0){
                    ans--;
                }
                r--;
            }while(r > qur[i].second);
        }

        qans[qur[i]] = ans;
    }

    for(auto elm : defq){
        cout << qans[elm] << "\n";
    }
    fflush(stdout);
}
