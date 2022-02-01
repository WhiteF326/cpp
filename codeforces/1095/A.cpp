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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  string ans = "";
  int sum = 0;
  for(int i = 0; i < 10; i++){
    ans += s[sum];
    sum += i + 1;
    if(sum >= n) break;
  }
  cout << ans << endl;
}