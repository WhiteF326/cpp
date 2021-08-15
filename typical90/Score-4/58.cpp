#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define gt(a, t) get<a>(t)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ti = tuple<int, int, int>;
using ll = long long;
using ld = long double;

int digsum(ll n){
  string s = to_string(n);
  int ans = 0;
  for(char c : s) ans += c - '0';
  return ans;
}

int main(){
  ll n, k; cin >> n >> k;
  map<int, int> prs;

  if(k <= 100000){
    for(int i = 0; i < k; i++){
      n = (n + digsum(n)) % 100000;
    }
    cout << n << endl;
    return 0;
  }

  int fn = n;
  for(int i = 0; i <= 100000; i++){
    n = (n + digsum(n)) % 100000;
    if(prs[n]){
      ll loop = i + 1 - prs[n];
      k = (k - prs[n]) % loop + prs[n];
      for(int j = 0; j <= 100000; j++){
        if(prs[j] == k){
          cout << j << endl;
          return 0;
        }
      }
    }else prs[n] = i + 1;
  }
}