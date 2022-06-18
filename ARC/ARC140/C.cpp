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
    
    int n, x; cin >> n >> x;
    
    int l = 1, r = n;
    deque<int> left, right;
    while(l < r){
        if(l != x) left.emplace_back(l);
        if(r != x) right.emplace_back(r);

        l++, r--;
    }

    if(l == r){
        if(l != x){
            (left.size() < right.size() ? left : right).emplace_back(l);
        }
    }

    if(left.size() < right.size()) swap(left, right);

    deque<int> ans = {x};

    while(!left.empty()){
        ans.emplace_back(left.back());
        left.pop_back();

        if(!right.empty()){
            ans.emplace_back(right.back());
            right.pop_back();
        }
    }

    for(int v : ans) cout << v << " ";
    cout << endl;
}
