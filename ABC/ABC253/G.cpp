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
    
    int n; cin >> n;
    ll l, r; cin >> l >> r;
    l--;

    vector<int> ans(n, 0);
    iota(all(ans), 1);

    // 左が i であるような swap 操作の回数
    vector<ll> div(n, 0);
    for(int i = 0; i < n; i++){
        div[i] = n - i - 1;
    }
    for(int i = 1; i < n; i++) div[i] += div[i - 1];

    auto act = [&](ll p){
        int left = upper_bound(all(div), p) - div.begin();
        int right = p - div[left] + n;
        cout << left << " " << right << endl;
        return make_pair(left, right);
    };

    int curleft = act(l).first;
    int next = 0;
    for(ll p = l; ; p++){
        auto v = act(p);
        if(v.first != curleft){
            next = v.first;
            break;
        }
        swap(ans[v.first], ans[v.second]);
    }

    auto itr = upper_bound(all(div), r);
    int end = itr - div.begin();
    itr--;

    vector<int> trans(0);
    trans.reserve(n);
    for(int i = 0; i < next; i++){
        trans.push_back(i);
    }
    for(int i = next; i < end; i++){
        trans.push_back(n - i - 1 + next);
    }
    for(int i = end; i < n; i++){
        trans.push_back(next + i - end);
    }

    vector<int> def(all(ans));
    for(int i = 0; i < n; i++) ans[i] = def[trans[i]];

    ll p = *itr;

    for(;p < r; p++){
        auto v = act(p);
        swap(ans[v.first], ans[v.second]);
    }

    for(int v : ans) cout << v << " ";
    cout << endl;
}
