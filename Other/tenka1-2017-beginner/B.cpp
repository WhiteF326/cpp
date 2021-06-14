#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  int n; cin >> n;
  priority_queue<pair<int, int>> q;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    q.push(make_pair(a, b));
  }
  cout << q.top().first + q.top().second << endl;
}