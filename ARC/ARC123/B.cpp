#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  sort(all(a)); sort(all(b)); sort(all(c));
  int bp = 0, cp = 0, ans = 0;

  for(int i = 0; i < n; i++){
    while(b[bp] <= a[i] && bp < b.size()) bp++;
    if(bp == b.size()) break;
    while(c[cp] <= b[bp] && cp < c.size()) cp++;
    if(cp == c.size()) break;
    ans++;
    bp++, cp++;
  }
  cout << ans << endl;
}