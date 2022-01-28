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
  if(n == 1 && m == 0){
    cout << "1 2" << endl;
    return 0;
  }
  if(m < 0 || m >= n - 1){
    cout << -1 << endl;
  }else{
    int start = 0;
    for(int i = 0; i < n - m - 2; i++){
      start += 2;
      cout << i * 2 + 1 << " " << i * 2 + 2 << "\n";
    }
    cout << start + 1 << " " << 1000000000 << "\n";
    for(int i = 0; i < m + 1; i++){
      cout << start + i * 2 + 2 << " " << start + i * 2 + 3 << "\n";
    }
    fflush(stdout);
  }
}