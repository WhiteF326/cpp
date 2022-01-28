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


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  deque<char> d;
  bool rev = false;
  for(char c : s){
    if(c == 'R'){
      rev = !rev;
    }else{
      if(!d.size()){
        d.push_back(c);
      }else{
        if(rev){
          // 末尾
          if(d.back() == c){
            d.pop_back();
          }else{
            d.push_back(c);
          }
        }else{
          // 先頭
          if(d.front() == c){
            d.pop_front();
          }else{
            d.push_front(c);
          }
        }
      }
    }
  }

  if(rev){
    while(!d.empty()){
      cout << d.front();
      d.pop_front();
    }cout << endl;
  }else{
    while(!d.empty()){
      cout << d.back();
      d.pop_back();
    }cout << endl;
  }
}