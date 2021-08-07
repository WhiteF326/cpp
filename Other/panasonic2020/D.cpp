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

const ll modv = 1000000007;

int n;
priority_queue<pdesc(string)> ansq;
vector<int> nl(0);

void dfs(int x, int prev){
  nl.push_back(x);
  if(nl.size() == n){
    string res = "";
    for(int v = 0; v < n; v++){
      res.push_back((char)'a' + nl[v] - 1);
    }
    ansq.push(res);
    nl.pop_back();
    return;
  }
  for(int i = 1; i <= min((int)nl.size() + 1, *max_element(all(nl)) + 1); i++) dfs(i, x);
  nl.pop_back();
}

int main(){
  cin >> n;
  dfs(1, 0);

  while(!ansq.empty()){
    cout << ansq.top() << endl;
    ansq.pop();
  }
}