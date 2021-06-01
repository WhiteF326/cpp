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
  vector<int> list((int)pow(2, n), 0);
  queue<int> q;
  for(int i = 0; i < pow(2, n); i++){
    int x; cin >> x;
    q.push(x);
    list[i] = x;
  }
  while(q.size() != 2){
    int d = q.front(); q.pop();
    int e = q.front(); q.pop();
    q.push(max(d, e));
  }
  int ansRate = q.front(); q.pop();
  ansRate = min(ansRate, q.front());
  cout << distance(list.begin(), find(list.begin(), list.end(), ansRate)) + 1 << endl;
}