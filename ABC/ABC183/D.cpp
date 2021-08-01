#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
using ll = long long;
using ld = long double;

constexpr int modv = 1000000007;

int main(){
  int n, w; cin >> n >> w;
	
  vector<ll> h(200001, 0);
  for(int i = 0; i < n; i++){
    int s, t; cin >> s >> t;
    ll p; cin >> p;
    h[s] += p, h[t] -= p;
  }

  for(int i = 1; i <= 200000; i++){
    h[i] += h[i - 1];
  }

  if(w < *max_element(h.begin(), h.end())) cout << "No" << endl;
  else cout << "Yes" << endl;
}