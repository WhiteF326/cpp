#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


vector<string> s(10);
int n, m;
bool res = false;
string ans = "";
vector<bool> diff(10, false);
void dfs(string cur){
  if(cur.length() == m){
    ans = cur;
    res = true;
    return;
  }else{
    int v = cur.length();
    for(char c = 'a'; c <= 'z'; c++){
      cur += c;
      bool nxt = true;
      set<int> turn;
      for(int i = 0; i < n; i++){
        if(diff[i] && s[i][v] != c){
          nxt = false;
          break;
        }else if(s[i][v] != c){
          turn.insert(i);
          diff[i] = true;
        }
      }
      if(nxt){
        dfs(cur);
      }
      for(int v : turn){
        diff[v] = false;
      }
      cur.pop_back();
    }
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  query(t){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    res = false;
    fill(all(diff), false);

    dfs("");

    if(res){
      cout << ans << endl;
    }else{
      cout << -1 << endl;
    }
  }
}