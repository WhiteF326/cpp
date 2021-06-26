// this problem was so fun :)

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

/*
  if X is correct brackets string then:
  (define length of X = L)
  * L is even number
  * from 1st to nth chars,
  *   the count of "(" is greater than or equal to the count of ")" (1 ~ n ~ L - 1)
  * the total count of "(" is equal to the total count of ")" is equal to L / 2
*/
void dfs(string s){
  if(s.length() == n){
    // should consist l = r = n / 2
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
  // amount of "(" is equal to amount of ")" is equal to n / 2
  cin >> n;
  if(n % 2) cout << endl;
  else{
    // generate from 2nd char by dfs
    r = 1;
    dfs("(");
  }
  // sort by lexical order ('(' < ')')
  sort(anslist.begin(), anslist.end());
  for(auto itr = anslist.begin(); itr != anslist.end(); itr++){
    cout << *itr << endl;
  }
}