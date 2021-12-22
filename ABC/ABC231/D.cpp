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
  int n, m; cin >> n >> m;

  vector<int> ctr(n, 0);
  dsu d(n);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    ctr[a - 1]++;
    ctr[b - 1]++;
    if(d.same(a - 1, b - 1)){
      cout << "No" << endl;
      return 0;
    }else{
      d.merge(a - 1, b - 1);
    }
  }

  if(*max_element(all(ctr)) > 2){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
}