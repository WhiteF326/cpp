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

  string s; cin >> s;
  int k; cin >> k;

  for(char& c : s){
    if(c == 'a') continue;
    int dist = 'z' - c + 1;
    if(dist > k){
      continue;
    }else{
      k -= dist;
      c = 'a';
    }
  }

  if(k){
    int n = s.length();
    k %= 26;
    for(int i = 0; i < k; i++){
      s[n - 1] += 1;
      if(s[n - 1] > 'z') s[n - 1] = 'a';
    }
  }

  cout << s << endl;
}