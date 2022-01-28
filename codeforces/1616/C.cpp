#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  int t; cin >> t;
  query(t){
    int n; cin >> n;

    vector<int> a(n);
    aryin(a, n);

    if(n == 1){
      cout << 0 << endl;
      continue;
    }

    // 階差にするのが適切
    int ans = n;
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        double diff = (a[i] - a[j]) / (double)abs(j - i);
        int res = 0;
        for(int k = 0; k < n; k++){
          double est = (i - k) * diff + a[i];
          if(est != (double)a[k]) res++;
        }
        ans = min(ans, res);
      }
      // 全て a[i] にする場合も一応考える
      int esv = 0;
      for(int j = 0; j < n; j++){
        if(a[i] != a[j]) esv++;
      }
      ans = min(ans, esv);
    }

    cout << ans << endl;
  }
}