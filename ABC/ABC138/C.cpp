#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  priority_queue<double, vector<double>, greater<double>> q;
  for(int i = 0; i < n; i++){
    double x; cin >> x;
    q.push(x);
  }
  while(q.size() > 1){
    double res = 0;
    for(int i = 0; i < 2; i++){
      res += q.top();
      q.pop();
    }
    q.push(res / 2.0);
  }
  cout << fs(12) << q.top() << endl;
}