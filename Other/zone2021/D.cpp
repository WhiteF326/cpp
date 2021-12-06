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
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  string s; cin >> s;
  deque<char> ans;
  bool rev = false;

  for(auto op : s){
    if(op == 'R'){
      rev = !rev;
    }else{
      if(rev){
        if(ans.size() && ans.front() == op){
          ans.pop_front();
        }else{
          ans.push_front(op);
        }
      }else{
        if(ans.size() && ans.back() == op){
          ans.pop_back();
        }else{
          ans.push_back(op);
        }
      }
    }
  }

  if(rev){
    for(auto itr = ans.rbegin(); itr != ans.rend(); itr++) cout << *itr;
    cout << endl;
  }else{
    for(auto c : ans) cout << c;
    cout << endl;
  }
}