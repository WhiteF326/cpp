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
  
  int n, k; cin >> n >> k;
  vector<int> v(n);
  aryin(v, n);

  int ans = 0;
  for(int left = 0; left <= n; left++){
    for(int right = 0; right <= n; right++){
      if(left + right > min(n, k)) break;
      deque<int> d(all(v));
      priority_queue<int, vector<int>, greater<int>> q;

      for(int i = 0; i < left; i++){
        q.push(d.front());
        d.pop_front();
      }
      for(int i = 0; i < right; i++){
        q.push(d.back());
        d.pop_back();
      }

      int lk = k - left - right;
      
      while(!q.empty() && q.top() < 0 && lk){
        q.pop();
        lk--;
      }
      int res = 0;
      while(!q.empty()){
        res += q.top();
        q.pop();
      }

      chmax(ans, res);
    }
  }

  cout << ans << endl;
}
