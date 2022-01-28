#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


const ll modv = 1000000007;
ll modpow(ll x, ll n){
  ll ret = 1;
  if(modv == 0){
    while(n > 0){
      if(n & 1) ret *= x;
      x *= x;
      n >>= 1;
    }
  }else{
    while(n > 0){
      if(n & 1) ret = ret * x % modv;
      x = x * x % modv;
      n >>= 1;
    }
  }
  return ret;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> mx(n, 0);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    mx[a]++;
  }

  if(n % 2){
    // 0x1, 残り2
    bool flg = true;
    if(mx[0] != 1) flg = false;
    for(int i = 2; i < n; i += 2){
      if(mx[i] != 2) flg = false;
    }
    cout << (flg ? modpow(2, n / 2) : 0) << endl;
  }else{
    // 全部2
    bool flg = true;
    for(int i = 1; i < n; i += 2){
      if(mx[i] != 2) flg = false;
    }
    cout << (flg ? modpow(2, n / 2) : 0) << endl;
  }
}