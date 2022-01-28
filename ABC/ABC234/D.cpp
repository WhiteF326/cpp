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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, k; cin >> n >> k;
  vector<int> p(n);
  aryin(p, n);

  vector<int> removed(n + 1, false);

  int current = n - k + 1;
  stack<int> ans;
  for(int i = n - 1; i >= k - 1; i--){
    ans.push(current);
    removed[p[i]] = true;
    if(p[i] >= current){
      // down 1
      current--;
      while(removed[current]) current--;
    }
  }
  while(!ans.empty()){
    cout << ans.top() << endl;
    ans.pop();
  }
}