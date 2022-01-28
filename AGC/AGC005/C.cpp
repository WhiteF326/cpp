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
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int n;
queue<int> cur;
bool ans = true;

void dfs(int rem){
  int v = cur.size();
  if(rem == 0){
    return;
  }
  int prm = cur.front();
  cout << prm << endl;
  int ctr = 0;
  while(cur.front() == prm){
    cur.pop();
    ctr++;
  }

  if(prm == 0 && ctr == 1){
    dfs(0);
  }else if(prm == 0 && ctr != 1){
    ans = false;
    return;
  }else if(prm == rem - 1){
    // all element, minus 1
    int x = cur.size();
    for(int i = 0; i < n; i++){
      cur.push(cur.front() - 1);
      cur.pop();
    }
    dfs(prm);
  }else{
    ans = false;
    return;
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  vector<int> a(n);
  aryin(a, n);

  sort(all(a), greater<int>());
  for(int i = 0; i < n; i++){
    cur.push(a[i]);
  }
  
  dfs(*max_element(all(a)) + 1);

  cout << (ans ? "Possible" : "Impossible") << endl;
}