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
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);
    sort(all(a));

    int o = 0, e = 0;
    for(int v : a){
      if(v % 2) o++;
      else e++;
    }

    if(o % 2 == 0){
      // e % 2 is also equal to 0
      cout << "YES" << endl;
    }else{
      bool flg = true;
      for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - a[i] == 1){
          cout << "YES" << endl;
          flg = false;
          break;
        }
      }
      if(flg) cout << "NO" << endl;
    }
  }
}