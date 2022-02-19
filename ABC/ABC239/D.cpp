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
  
  vector<bool> ert(201, true);
  ert[1] = false;
  for(int p = 2; p * p <= 200; p++){
    if(!ert[p]) continue;
    for(int j = p * 2; j <= 200; j += p){
      ert[j] = false;
    }
  }

  int a, b, c, d; cin >> a >> b >> c >> d;
  for(int i = a; i <= b; i++){
    bool v = false;
    for(int j = c; j <= d; j++){
      if(ert[i + j]) v = true;
    }
    if(!v){
      cout << "Takahashi" << endl;
      return 0;
    }
  }

  cout << "Aoki" << endl;
}
