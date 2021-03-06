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
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string x; cin >> x;
  int n = x.length();
  vector<int> digit(n, 0);
  for(int i = 0; i < n; i++) digit[i] = x[i] - '0';

  int cur = accumulate(all(digit), 0);
  int curry = 0;
  deque<int> d;

  for(int i = 0; i < n; i++){
    // cout << cur << " " << curry << endl;
    d.push_back((cur + curry) % 10);
    curry = (cur + curry) / 10;
    cur -= digit[n - 1 - i];
  }
  while(curry != 0){
    d.push_back(curry % 10);
    curry /= 10;
  }

  while(!d.empty()){
    cout << d.back();
    d.pop_back();
  }
  cout << endl;
}