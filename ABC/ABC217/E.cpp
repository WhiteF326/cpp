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
#define aryin(a, n) vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

int main(){
  int t; cin >> t;

  queue<int> q;
  priority_queue<int, vector<int>, greater<int>> p;

  query(t){
    int c; cin >> c;
    if(c == 1){
      int x; cin >> x;
      q.push(x);
    }else if(c == 2){
      if(p.size()){
        cout << p.top() << endl;
        p.pop();
      }else{
        cout << q.front() << endl;
        q.pop();
      }
    }else{
      while(!q.empty()){
        p.push(q.front());
        q.pop();
      }
    }
  }
}