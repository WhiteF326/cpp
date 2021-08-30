#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int main(){
  ios::sync_with_stdio(false);
  
  int t; cin >> t;
  for(int i = 0; i < t; i++){
    int n; cin >> n;

    vector<int> cnt(2, 0);
    queue<int> p;
    
    for(int i = 0; i < n; i++){
      int a; cin >> a;
      if(a % 2) p.push(i);
      cnt[a % 2]++;
    }

    if(abs(cnt[0] - cnt[1]) > 1){
      cout << -1 << endl;
      continue;
    }

    int ans = 10000000;
    for(int start = 0; start < 2; start++){
      int ps = start;
      queue<int> q(p);
      if(start == 0 && cnt[0] > cnt[1]) continue;
      if(start == 1 && cnt[0] < cnt[1]) continue;
      int res = 0;
      while(!q.empty()){
        res += abs(q.front() - ps);
        ps += 2;
        q.pop();
      }
      ans = min(ans, res);
    }

    cout << ans << endl;
  }
}