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
  vector<int> a(n + 1, 0);
  vector<int> b(n + 1, 0);

  for(int i = 0; i < n; i++) cin >> a[i + 1];

  for(int i = n; i >= 1; i--){
    int f = 0;
    for(int x = i * 2; x <= n; x += i){
      if (b[x]) f++;
    }
    if((f & 1) != a[i]) b[i] = 1;
  }

  vector<int> ans(0);
  for(int i = 1; i <= n; i++){
    if(b[i]) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for(int v : ans){
    cout << v << " ";
  }cout << endl;
}
