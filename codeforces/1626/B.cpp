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
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int tt; cin >> tt;
  query(tt){
    string x; cin >> x;
    int n = x.length();

    bool en = false;
    for(int i = n - 2; i >= 0; i--){
      if(x[i] + x[i + 1] - '0' * 2 >= 10){
        // 最後で操作する
        cout << x.substr(0, i);
        cout << x[i] + x[i + 1] - '0' * 2;
        cout << x.substr(i + 2) << endl;
        en = true;
        break;
      }
    }
    if(!en){
      cout << x[0] + x[1] - '0' * 2;
      cout << x.substr(2) << endl;
    }
  }
}