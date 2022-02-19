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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> p(n);
  aryin(p, n);

  bool asc = true;
  if(p[0] == p[1] + 1) asc = false;
  if(p[0] == 1 && p[1] == n) asc = false;

  int ans = 1 << 30;

  if(asc){
    for(int i = 0; i < n; i++){
      if(p[i] == 1){
        chmin(ans, i);
        chmin(ans, (n - i) + 2);
        break;
      }
    }
  }else{
    for(int i = 0; i < n; i++){
      if(p[i] == n){
        chmin(ans, i + 1);
        chmin(ans, (n - i) + 1);
        break;
      }
    }
  }

  cout << ans << endl;
}