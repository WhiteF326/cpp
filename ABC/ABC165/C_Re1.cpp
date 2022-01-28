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


int n, m, q;
vector<int> a(50), b(50), c(50), d(50);
vector<int> cur;
int ans = 0;

void dfs(int p, int size){
  if(size == n){
    int res = 0;
    for(int i = 0; i < q; i++){
      if(cur[b[i] - 1] - cur[a[i] - 1] == c[i]) res += d[i];
    }
    ans = max(ans, res);
    return;
  }
  for(int i = max(1, p); i <= m; i++){
    cur.push_back(i);
    dfs(i, size + 1);
    cur.pop_back();
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m >> q;

  for(int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  dfs(0, 0);

  cout << ans << endl;
}