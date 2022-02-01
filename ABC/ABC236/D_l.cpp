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


int n;

vector<vector<int>> trd(16, vector<int>(16, 0));


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  n *= 2;

  vector<int> res(30, 0);
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      int a; cin >> a;
      trd[i][j] = a;
      trd[j][i] = a;
      for(int k = 0; k < 30; k++){
        if(a & (1 << k)) res[k]++;
      }
    }
  }

  for(int v : res) cout << v << " ";
  cout << endl;
}