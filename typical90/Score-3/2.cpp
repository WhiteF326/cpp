#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int n;
int l = 0, r = 0;
vector<string> anslist;

void dfs(string s){
  if(s.length() == n){
    anslist.emplace_back(s);
    return;
  }else{
    if(r < n / 2){
      r++;
      dfs(s + "(");
      r--;
    }
    if(l < n / 2 && r > l){
      l++;
      dfs(s + ")");
      l--;
    }
  }
}

int main(){
  cin >> n;
  if(n % 2) cout << endl;
  else{
    // 2から順に生成する
    r = 1;
    dfs("(");
  }
  sort(anslist.begin(), anslist.end());
  for(auto itr = anslist.begin(); itr != anslist.end(); itr++){
    cout << *itr << endl;
  }
}