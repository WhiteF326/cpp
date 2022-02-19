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
  
  int n, m; cin >> n >> m;
  vector<ll> a(n);
  aryin(a, n);
  sort(all(a));
  vector<pair<ll, int>> b(m);
  for(int i = 0; i < m; i++){
    cin >> b[i].first >> b[i].second;
  }
  sort(all(b), [](const pair<int, int>& left, const pair<int, int>& right){
    return left.second > right.second;
  });

  int ptr = 0;
  for(int i = 0; i < n; i++){
    if(a[i] < b[ptr].second){
      a[i] = b[ptr].second;
      b[ptr].first--;
      if(!b[ptr].first){
        ptr++;
      }
      if(ptr == m){
        break;
      }
    }else{
      break;
    }
  }

  cout << accumulate(all(a), 0LL) << endl;
}
