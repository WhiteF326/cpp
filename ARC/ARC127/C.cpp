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
  
  int n; cin >> n;
  string x; cin >> x;
  int t = 0;

  reverse(all(x));
  while(x.length() < n) x += '0';

  for(int i = 0; i < n; i++) t += x[i] == '1';
  
  auto s = [&](){
    int i = 0;
    for(; x[i] == '0'; i++){
      x[i] = '1';
      t++;
    };
    x[i] = '0';
    t--;
  };
  s();

  string ans = "1";
  
  for(int i = n - 1; i >= 0; i--){
    if(t == 0) break;
    ans += x[i];
    if(x[i] == '1'){
      t--;
    }else{
      s();
    }
  }
  cout << ans << endl;
}