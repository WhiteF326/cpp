#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)


vector<string> divd = {
  "dream", "dreamer", "erase", "eraser"
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();

  queue<int> q;
  q.push(0);
  vector<bool> visited(n, false);
  visited[0] = true;
  bool ans = false;

  while(!q.empty()){
    int dest = q.front();
    q.pop();
    if(dest == n){
      ans = true;
      break;
    }

    for(auto d : divd){
      if(d == s.substr(dest, d.length())){
        int nxt = dest + d.length();
        if(!visited[nxt]){
          q.push(nxt);
          visited[nxt] = true;
        }
      }
    }
  }

  cout << (ans ? "YES" : "NO") << endl;
}