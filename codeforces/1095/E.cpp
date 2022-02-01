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
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    v[i] = s[i] == '(' ? 1 : -1;
  }
  vector<int> vs(all(v));
  for(int i = 1; i < n; i++){
    vs[i] += vs[i - 1];
  }

  int sv = vs[n - 1];
  if(sv != 2 && sv != -2){
    cout << 0 << endl;
    return 0;
  }else{
    vector<int> mx(n);
    mx[n - 1] = sv;
    for(int i = n - 2; i >= 0; i--){
      mx[i] = min(mx[i + 1], vs[i]);
    }
    for(int i = 1; i < n; i++){
      vs[i] = min(vs[i - 1], vs[i]);
    }

    int ans = 0;
    if(v[0] == 1 && mx[0] >= 2 && sv == 2) ans++;
    else if(v[0] == -1 && mx[0] >= -2 && sv == -2) ans++;

    for(int i = 1; i < n; i++){
      if(v[i] == 1){
        if(vs[i - 1] >= 0 && mx[i] >= 2 && sv == 2) ans++;
      }else if(vs[i - 1] >= 0 && mx[i] >= -2 && sv == -2) ans++;
    }

    cout << ans << endl;
  }
}