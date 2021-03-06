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


int a, n;
int ans = INT_MAX;
vector<bool> visited(10000001, 0);
void dfs(ll cur, int depth){
  if(visited[cur]) return;
  visited[cur] = true;
  if(cur == 1){
    ans = min(ans, depth);
    return;
  }
  if(cur % a == 0) dfs(cur / a, depth + 1);
  string s = to_string(cur);
  s = s.substr(1) + s[0];
  dfs(stoi(s), depth + 1);
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, q; cin >> n >> q;

  unordered_map<int, vector<int>> m;
  vector<int> a(n);
  aryin(a, n);

  for(int i = 0; i < n; i++){
    m[a[i]].push_back(i + 1);
  }

  query(q){
    int x, k; cin >> x >> k;
    if(m[x].size() < k){
      cout << -1 << endl;
    }else{
      cout << m[x][k - 1] << endl;
    }
  }
}