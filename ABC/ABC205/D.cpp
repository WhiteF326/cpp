#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int op(int a, int b){
  return min(a, b);
}

int e(){
  return INT_MAX;
}

int main(){
  ll n, q; cin >> n >> q;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  vector<vector<ll>> len(1, vector<ll>(1, a[0]));
  for(ll i = 1; i < n; i++){
    if(a[i - 1] + 1 == a[i]){
      len[len.size() - 1].emplace_back(a[i]);
    }else{
      len.emplace_back(vector<ll>());
      len[len.size() - 1].emplace_back(a[i]);
    }
  }
  vector<ll> rangeMin(len.size(), 0);
  for(ll i = 0; i < len.size(); i++) rangeMin[i] = len[i][0];
  vector<ll> lenss(len.size(), len[0].size());
  for(ll i = 1; i < len.size(); i++){
    lenss[i] = lenss[i - 1] + len[i].size();
  }
  vector<ll> k(q);
  for(ll i = 0; i < q; i++){
    ll k; cin >> k;
    if(rangeMin[0] > k) cout << k << endl;
    else if(rangeMin[len.size() - 1] < k) cout << k + n << endl;
    else{
      vector<ll> v(rangeMin);
      v.emplace_back(k);
      ll res = lower_bound(v.begin(), v.end(), k) - v.begin();
      cout << k + lenss[res] << endl;
    }
  }
}