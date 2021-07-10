#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

constexpr ll modv = 1000000007;

int main(){
  ll n, m; cin >> n >> m;

  // factテーブル
  vector<ll> factlist(100001, 1);
  for(int i = 1; i <= 100000; i++) factlist[i] = factlist[i - 1] * i % modv;

  if(abs(n - m) > 1){
    cout << 0 << endl;
  }else if(n == m){
    cout << (factlist[n] * factlist[m] * 2) % modv << endl;
  }else{
    cout << (factlist[n] * factlist[m]) % modv << endl;
  }
}