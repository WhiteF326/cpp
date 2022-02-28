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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  string s; cin >> s;

  queue<char> q;
  for(int c : s){
    if(c == 'A'){
      q.push('B');
      q.push('B');
    }else q.push(c);
  }
  string ans = "";
  while(!q.empty()){
    char p = q.front();
    q.pop();

    if(q.empty()){
      ans += p;
    }else if(q.front() == 'B' && p == 'B'){
      q.pop();
      ans += 'A';
    }else{
      ans += p;
    }
  }

  cout << ans << endl;
}
