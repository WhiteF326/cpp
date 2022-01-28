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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, m; cin >> n >> m;

  set<int> st;
  for(int i = 1; i * i <= m; i++){
    if(m % i == 0){
      st.insert(i);
      st.insert(m / i);
    }
  }
 
  int ans = 1;
  for(int v : st){
    if(m / v >= n){
      ans = v;
    }
  }
 
  cout << ans << endl;
}