// edited code, from gabriel55_

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
#define all(x) x.begin(), x.end()
#define rep(i, x) for (ll i = 0, acnx = (x); i < acnx; ++i)

struct stru {
  string s;
  ll p;
  ll num;
};

bool operator< (const stru& left, const stru& right){
  return left.s == right.s ? left.p > right.p : left.s < right.s;
}

int main(void) {
  ll n;
  cin >> n;

  vector<stru> r(n);

  rep(i,n){
    cin >> r[i].s >> r[i].p;
    r[i].num = i+1;
  }

  sort(all(r));

  rep(i,n) cout << r[i].num << '\n';
  return 0;
}