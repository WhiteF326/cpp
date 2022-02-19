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

  reverse(all(s));

  deque<int> q;
  q.push_back(n);

  int cur = n - 1;
  for(char c : s){
    if(c == 'L'){
      q.push_back(cur);
    }else{
      q.push_front(cur);
    }
    cur--;
  }

  for(int i = 0; i < n + 1; i++){
    cout << q.front() << " ";
    q.pop_front();
  }cout << endl;
}
