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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s; cin >> s;
  int n = s.length();
  vector<int> d(3, 0);
  int sum = 0;
  for(char c : s){
    int v = c - '0';
    d[v % 3]++;
    sum += v;
  }
  if(sum % 3 == 0){
    cout << 0 << endl;
  }else if(sum % 3 == 1){
    if(d[1] >= 1 && n > 1){
      cout << 1 << endl;
    }else if(d[2] >= 2 && n > 2){
      cout << 2 << endl;
    }else{
      cout << -1 << endl;
    }
  }else{
    if(d[2] >= 1 && n > 1){
      cout << 1 << endl;
    }else if(d[1] >= 2 && n > 2){
      cout << 2 << endl;
    }else{
      cout << -1 << endl;
    }
  }
}