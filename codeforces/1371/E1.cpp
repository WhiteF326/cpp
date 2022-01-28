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
  
  int n, p; cin >> n >> p;
  vector<int> a(n);
  aryin(a, n);

  sort(all(a));

  queue<int> q;

  for(int i = a[0]; i <= a[n - 1]; i++){
    // dp[i] = i 番目の要素を選んだ時点での通り数
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for(int j = 0; j < n; j++){
      // current = i + j
      ll ins = i + j - a[j] + 1;
      ins = min(ins, (ll)j + 1LL);
      dp[j + 1] = (dp[j] * max(ins, 0LL)) % p;
    }
    if(dp[n]) q.push(i);
  }
  cout << q.size() << endl;
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }cout << endl;
}