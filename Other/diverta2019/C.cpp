#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  // 末尾がaかつ先頭がbの扱い？
  int n; cin >> n;
  ll ans = 0;
  vector<ll> abcnt(3, 0);
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    // 内包ABは普通に検索しておｋ
    for(int j = 0; j < s.length() - 1; j++){
      if(s.substr(j, 2) == "AB"){
        ans++;
      }
    }
    if(s.back() == 'A'){
      if(s.front() == 'B'){
        abcnt[2]++;
      }else{
        abcnt[0]++;
      }
    }else if(s.front() == 'B'){
      abcnt[1]++;
    }
  }
  if(abcnt[0] == abcnt[1]) abcnt[2] = max(0LL, abcnt[2] - 1);
  cout << ans + max(0LL, min(abcnt[0], abcnt[1]) + abcnt[2]) << endl;

}