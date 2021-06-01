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
  vector<int> list(n);
  priority_queue<int> a;
  for(int i = 0; i < n; i++){
    int s; cin >> s;
    a.push(s);
    list[i] = s;
  }
  int mx = a.top(); a.pop();
  int sec = a.top();
  for(int i = 0; i < n; i++){
    if(mx == list[i]) cout << sec << endl;
    else cout << mx << endl;
  }

}