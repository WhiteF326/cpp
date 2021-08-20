#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
#define chmin(a, b) a = min(a, b)
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  string x; cin >> x;

  int tc = count(all(x), '1');
  for(int i = 0; i < n; i++){
    int t = tc;
    if(x[i] == '1') tc++;
    
  }
}