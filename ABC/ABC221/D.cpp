#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int n; cin >> n;
  map<int, int> rs;
  rs[0] = 0;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    rs[a]++, rs[a + b]--;
  }

  int m = rs.size();
  vector<int> dl(m);
  vector<int> vs(m);
  auto itr = rs.begin();
  for(int p = 0; p < m; p++){
    dl[p] = itr->first;
    vs[p] = itr->second;
    itr++;
  }
  for(int i = 1; i < m; i++) vs[i] += vs[i - 1];

  // for(int p = 0; p < m; p++){
  //   cout << dl[p] << " " << vs[p] << endl;
  // }

  vector<int> anslist(n + 1, 0);
  
  int ptr = 0;
  for(int i = 0; i < m - 1; i++){
    anslist[vs[i]] += (dl[i + 1] - dl[i]);
  }
  for(int i = 1; i <= n; i++){
    cout << anslist[i] << " ";
  }cout << endl;
}