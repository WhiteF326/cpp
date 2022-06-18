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
    int first, second, no;
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n); aryin(a, n);
    vector<int> b(n); aryin(b, n);

    vector<int> c(all(a));
    for(int i = 0; i < n; i++) c.push_back(b[i]);
    sort(all(c));
    c.erase(unique(all(c)), c.end());
    for(int i = 0; i < n; i++) a[i] = lower_bound(all(c), a[i]) - c.begin();
    for(int i = 0; i < n; i++) b[i] = lower_bound(all(c), b[i]) - c.begin();

    int q; cin >> q;

    vector<qt> qur(q);
    for(int i = 0; i < q; i++) cin >> qur[i].first >> qur[i].second;
    for(int i = 0; i < q; i++) qur[i].first--, qur[i].second--, qur[i].no = i;

    vector<int> alist(q);

    sort(all(qur), [&](const qt& lhs, const qt& rhs){
        if(lhs.first == rhs.first){
            return lhs.second < rhs.second;
        }else{
            return lhs.first < rhs.first;
        }
    });

    set<int> as;
    set<int> bs;
    set<int> cs;
    int r = 0;
    vector<bool> dead(n, false);
    vector<int> left(n, INT_MAX), right(n, INT_MAX);
    for(int l = 0; l < n; l++){
        as.insert(a[l]);
        cs.insert(a[l]);
        bool cont = false;
        while(as.size()){
            if(r == n){
                cont = true;
                break;
            }
            auto itr = as.find(b[r]);
            if(cs.find(b[r]) == cs.end()){
                bs.insert(b[r]);
            }else{
                if(as.find(b[r]) != as.end()) as.erase(as.find(b[r]));
            }
            r++;
        }
        if(cont) break;
        left[l] = r;
        if(bs.size()) dead[l] = true;

        while(true){
            if(r == n){
                break;
            }
            if(cs.find(b[r]) == cs.end()){
                break;
            }
            r++;
        }
        right[l] = r;
    }

    for(int i = 0; i < n; i++){
        cout << left[i] << " " << right[i] << endl;
    }

    for(int i = 0; i < q; i++){
        if(dead[qur[i].first]) alist[qur[i].no] = 0;
        else{
            if(left[qur[i].first] <= qur[i].second && qur[i].second <= right[qur[i].first]){
                alist[qur[i].no] = 1;
            }else{
                alist[qur[i].no] = 0;
            }
        }
    }

    for(int v : alist) cout << (v ? "Yes": "No") << endl;
}
