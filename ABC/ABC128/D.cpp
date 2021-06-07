#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  deque<int> v;
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    v.push_back(x);
  }
  priority_queue<int, vector<int>, greater<int>> self;
  int ans = accumulate(v.begin(), v.end(), 0);
  for(int i = 0; i < k; i++){
    //
  }
}