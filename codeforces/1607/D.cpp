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
    vector<int> p(n);
    aryin(p, n);
    string s; cin >> s;
    
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
      if(s[i] == 'R'){
        v[i] = {p[i], INT_MAX};
      }else{
        v[i] = {INT_MIN, p[i]};
      }
    }

    sort(all(v), [](const pair<int, int>& a, const pair<int, int>& b){
      if(a.second == b.second){
        return a.first < b.first;
      }else{
        return a.second < b.second;
      }
    });

    bool flg = false;
    for(int i = 1; i <= n; i++){
      if(v[i - 1].second < i || v[i - 1].first > i){
        cout << "NO" << endl;
        flg = true;
        break;
      }
    }
    if(!flg) cout << "YES" << endl;
  }
}