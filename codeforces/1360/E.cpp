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
    vector<vector<bool>> stage(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++){
      string s; cin >> s;
      for(int j = 0; j < n; j++){
        if(s[j] == '1') stage[i][j] = true;
      }
    }

    bool ans = true;
    for(int i = 0; i < n - 1; i++){
      for(int j = 0; j < n - 1; j++){
        if(!stage[i][j]) continue;
        if(!stage[i][j + 1] && !stage[i + 1][j]){
          ans = false;
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}