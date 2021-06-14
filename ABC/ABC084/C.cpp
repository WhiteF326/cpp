#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  vector<tuple<ll, ll, ll>> tr(n);
  for(int i = 0; i < n - 1; i++){
    ll c, s, f; cin >> c >> s >> f;
    tr[i] = make_tuple(c, s, f);
  }
  for(int i = 0; i < n - 1; i++){
    ll t = 0;
    for(int j = i; j < n - 1; j++){
      // 今いる駅の最もすぐ発車する電車
      ll c = get<0>(tr[j]), s = get<1>(tr[j]), f = get<2>(tr[j]);
      if(t < s) t = s;
      else if(t % f == 0);
      else t = t + f - t % f;
      t += c;
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}