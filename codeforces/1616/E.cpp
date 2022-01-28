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
    string s, t; cin >> s >> t;

    bool flg = true;
    for(char c : t){
      if(c != 'a') flg = false;
    }
    if(flg){
      cout << -1 << endl;
      continue;
    }

    if(s < t){
      cout << 0 << endl;
      continue;
    }

    // ns[c][i] = 
    // what is the next index of a charactor smaller than or equal to c, from t[i]? 
    vector<vector<int>> ns(26, vector<int>(n + 1, INT_MAX));
    for(int i = n - 1; i > 0; i--){
      for(int j = 0; j < 26; j++) ns[j][i - 1] = ns[j][i];
      for(int j = t[i] - 'a'; j < 26; j++){
        ns[j][i - 1] = i;
      }
    }

    ll ans = 0;
    bool cflg = true;
    for(int x = 0; x < 2; x++){
      if(s < t){
        break;
      }
      for(int i = 0; i < n; i++){
        if(x){
          if(s[i] < t[i]) continue;
        }else{
          if(s[i] <= t[i]) continue;
        }
        cout << i << " " << ns[s[i] - 'a'][i] << endl;
        if(ns[s[i] - 'a'][i] == INT_MAX){
          cflg = false;
          break;
        }
        ans += ns[s[i] - 'a'][i] - i;
        swap(s[i], s[ns[s[i] - 'a'][i]]);
        if(s < t){
          break;
        }
        cout << s << endl;
      }
    }
    if(cflg){
      if(s == t){
        ans++;
      }
      cout << ans << endl;
    }else{
      cout << -1 << endl;
    }
  }
}