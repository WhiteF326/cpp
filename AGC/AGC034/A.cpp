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
  int a, b, c, d; cin >> a >> b >> c >> d;
  a--, b--, c--, d--;
  string s; cin >> s;

  vector<bool> stg(n);
  for(int i = 0; i < n; i++) stg[i] = s[i] == '#';

  for(int i = a; i <= min(max(c, d), n - 2); i++){
    if(stg[i] && stg[i + 1]){
      cout << "No" << endl;
      return 0;
    }
  }
  if(c < d){
    cout << "Yes" << endl;
    return 0;
  }
  for(int i = max(b, 1); i <= d; i++){
    if(!stg[i - 1] && !stg[i] && !stg[i + 1]){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}