#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int mx = 1000000;
vector<int> ert(mx + 1, 0);
vector<int> lst;
int c = 1;
void dfs(const vector<pair<int, int>>& p, int cur){
  if(cur == p.size()){
    lst.emplace_back(c);
    return;
  }
  int b = c;
  for(int i = 0; i <= p[cur].second; i++){
    dfs(p, cur + 1);
    c *= p[cur].first;
  }
  c = b;
}
void refx(const unordered_map<int, int>& p){
  lst.erase(all(lst));
  lst.shrink_to_fit();

  vector<pair<int, int>> v;
  for(auto x : p){
    v.push_back({x.first, x.second});
  }

  dfs(v, 0);
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(n);
  aryin(a, n);

  for(int i = 2; i <= mx; i++){
    if(ert[i]) continue;
    for(int j = i; j <= mx; j += i){
      ert[j] = i;
    }
  }

  vector<bool> exs(mx + 1, 0);
  for(int v : a) exs[v] = true;

  vector<int> ctr(mx + 1, 0);
  for(int v : a){
    int x = v;
    unordered_map<int, int> m;
    while(x != 1){
      m[ert[x]]++;
      x /= ert[x];
    }
    m[1] = 1;
    refx(m);
    for(int v : lst){
      ctr[v]++;
      cout << v << " ";
    }cout << endl;
  }

  int ans = 0;
  for(int i = 0; i <= mx; i++){
    if(!exs[i] && ctr[i] >= 2){
      ans++;
    }
  }
  cout << ans << endl;
}