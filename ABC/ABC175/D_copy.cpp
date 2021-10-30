#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) ifs >> a[i];


int main(){
  ifstream ifs("08.txt");
  int n, k; ifs >> n >> k;
  vector<ll> p(n); aryin(p, n);
  vector<ll> c(n); aryin(c, n);

  dsu d(n);
  for(int i = 0; i < n; i++){
    d.merge(i, p[i] - 1);
  }

  vector<ll> anslist;

  if(k <= 5000){
    // 愚直
    for(int i = 0; i < n; i++){
      ll mx = 0, res = 0;
      int pt = i;
      for(int j = 0; j < k; j++){
        res += c[p[pt] - 1];
        if(mx) mx = max(mx, res);
        else mx = res;
        pt = p[pt] - 1;
      }
      anslist.push_back(mx);
    }
    sort(all(anslist));
    cout << anslist[n - 1] << endl;
  }else{
    for(int i = 0; i < n; i++){
      int loop = d.size(i);
      vector<ll> past;
      ll res = 0;
      int pt = i;
      for(int step = 0; step < loop; step++){
        res += c[p[pt] - 1];
        past.push_back(res);
        pt = p[pt] - 1;
      }
      if(res > 0){
        // 限界まで回る
        ll rv = res * (k / loop);
        ll rr1 = rv, rr2 = rv;
        int last = k % loop;
        if(last){
          rr1 += *max_element(past.begin(), past.begin() + last);
        }
        rr2 -= res;
        rr2 += *max_element(all(past));
        anslist.push_back(max(rr1, rr2));
      }else{
        anslist.push_back(*max_element(all(past)));
      }
    }

    cout << *max_element(all(anslist)) << endl;
  }
}