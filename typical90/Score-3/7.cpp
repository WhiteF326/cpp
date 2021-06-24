#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  queue<int> anslist;

  int q; cin >> q;
  for(int _ = 0; _ < q; _++){
    int b; cin >> b;
    auto itr = upper_bound(a.begin(), a.end(), b);
    int pos = itr - a.begin();
    int res = INT_MAX;
    for(int i = pos - 2; i <= pos + 2; i++){
      if(i >= 0 && i < n){
        res = min(res, abs(b - a[i]));
      }
    }
    anslist.push(res);
  }
  for(int i = 0; i < q; i++){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}